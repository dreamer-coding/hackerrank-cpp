import re
import sys
import os
from threading import Thread
from queue import Queue

class SkipPlugin:
    def __init__(self):
        self.skip_list = []

    def add_skip(self, path):
        self.skip_list.append(path)

    def should_skip(self, path):
        for skip_path in self.skip_list:
            if path.startswith(skip_path):
                return True
        return False

class Linter:
    def __init__(self, skip_plugin=None):
        self.errors = []
        self.skip_plugin = skip_plugin

    def lint_file(self, file_path):
        if self.skip_plugin and self.skip_plugin.should_skip(file_path):
            return
        errors = []
        with open(file_path, 'r') as file:
            lines = file.readlines()
            for i, line in enumerate(lines):
                # Check for trailing whitespace
                if re.search(r'\s+$', line):
                    errors.append(f"Line {i+1}: Trailing whitespace found")

                # Check for missing semicolon
                if not line.strip().endswith(';') and not line.strip().startswith('#'):
                    errors.append(f"Line {i+1}: Missing semicolon")

                # Check indentation
                if re.match(r'^[ \t]*\S', line) and not re.match(r'^[ \t]*[{}]', line):
                    errors.append(f"Line {i+1}: Indentation issue")

                # Check for consistent indentation (use spaces only)
                if re.match(r'^\t', line):
                    errors.append(f"Line {i+1}: Inconsistent indentation, use spaces only")

                # Check for consistent spacing around operators
                operators = ['+', '-', '*', '/', '=', '==', '!=', '<', '>', '<=', '>=']
                for op in operators:
                    if re.search(fr'\S{op}\s', line) or re.search(fr'\s{op}\S', line):
                        errors.append(f"Line {i+1}: Inconsistent spacing around operator '{op}'")

                # Check line length
                if len(line.rstrip()) > 80:
                    errors.append(f"Line {i+1}: Line length exceeds 80 characters")

                # Check for banned constructs: goto and gets
                if re.search(r'\b(?:goto|gets)\b', line):
                    errors.append(f"Line {i+1}: Banned construct used (goto or gets)")

                # Check for braces on the same line as control structure
                if re.search(r'\b(?:if|else|for|while|do)\b', line) and not re.search(r'{\s*$', line):
                    errors.append(f"Line {i+1}: Braces should be on the same line as control structure")

                # Check for magic numbers
                if re.search(r'\b\d+\b', line):
                    errors.append(f"Line {i+1}: Avoid using magic numbers")

                # Enforce consistent naming conventions (example: camelCase)
                if re.search(r'\b[A-Z][a-zA-Z0-9]*\b', line):
                    errors.append(f"Line {i+1}: Use camelCase naming convention")

                # Detect unused header files
                if re.search(r'^#include\s+<([a-zA-Z0-9_]+\.[hH])>', line):
                    header_file = re.search(r'^#include\s+<([a-zA-Z0-9_]+\.[hH])>', line).group(1)
                    if not re.search(r'\b{}\b'.format(header_file.split('.')[0]), ''.join(lines[i+1:])):
                        errors.append(f"Line {i+1}: Unused header file '{header_file}'")

                # Check for redundant code (example: empty if statements)
                if re.match(r'^\s*if\s*\(\s*.*\s*\)\s*{\s*}\s*$', line):
                    errors.append(f"Line {i+1}: Redundant code - empty if statement")

        self.errors.extend(errors)

    def lint_directory(self, directory):
        for root, _, files in os.walk(directory):
            for file in files:
                if file.endswith(('.c', '.cpp', '.h', '.hpp', '.m', '.mm')):
                    file_path = os.path.join(root, file)
                    self.lint_file(file_path)

    def lint_concurrently(self, directory, num_threads=4):
        queue = Queue()

        def worker():
            while True:
                file_path = queue.get()
                if file_path is None:
                    break
                self.lint_file(file_path)
                queue.task_done()

        threads = []
        for _ in range(num_threads):
            thread = Thread(target=worker)
            thread.start()
            threads.append(thread)

        for root, _, files in os.walk(directory):
            for file in files:
                if file.endswith(('.c', '.cpp', '.h', '.hpp', '.m', '.mm')):
                    file_path = os.path.join(root, file)
                    queue.put(file_path)

        queue.join()

        # Stop workers
        for _ in range(num_threads):
            queue.put(None)
        for thread in threads:
            thread.join()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python fossil-linter.py <directory>")
        sys.exit(1)

    target = sys.argv[1]
    if not os.path.isdir(target):
        print("Invalid directory.")
        sys.exit(1)

    # Create and configure linter
    linter = Linter()
    skip_plugin = SkipPlugin()
    skip_plugin.add_skip("subprojects/")  # Skip third-party libraries
    linter.skip_plugin = skip_plugin

    # Perform linting
    linter.lint_concurrently(target)

    # Print errors
    if linter.errors:
        for error in linter.errors:
            print(error)
        sys.exit(1)
    else:
        print("No errors found.")
