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

class CodeFormatterLinter:
    def __init__(self, skip_plugin=None):
        self.errors = []
        self.skip_plugin = skip_plugin

    def lint_file(self, file_path):
        if self.skip_plugin and self.skip_plugin.should_skip(file_path):
            return
        errors = []
        with open(file_path, 'r') as file:
            lines = file.readlines()
            in_block_comment = False
            for i, line in enumerate(lines):
                stripped_line = line.strip()
                
                # Skip block comments
                if in_block_comment:
                    if '*/' in stripped_line:
                        in_block_comment = False
                    continue
                elif stripped_line.startswith('/*'):
                    in_block_comment = True
                    continue
                
                # Skip single-line comments
                if stripped_line.startswith('//'):
                    continue

                # Check for trailing whitespace
                if re.search(r'\s+$', line):
                    errors.append(f"{file_path}: Line {i+1}: Trailing whitespace found")

                # Check indentation (use 4 spaces)
                if re.match(r'^\t', line):
                    errors.append(f"{file_path}: Line {i+1}: Inconsistent indentation, use spaces only")
                elif re.match(r'^( {1,3}|\t+)', line):
                    errors.append(f"{file_path}: Line {i+1}: Indentation should be 4 spaces")

                # Check line length
                if len(line.rstrip()) > 80:
                    errors.append(f"{file_path}: Line {i+1}: Line length exceeds 80 characters")

                # Check for consistent spacing around operators (one space around operators)
                operators = ['\+', '-', '\*', '/', '=', '==', '!=', '<', '>', '<=', '>=']
                for op in operators:
                    if re.search(fr'\S{op}\s|\s{op}\S', line) and not re.search(fr'\s{op}\s', line):
                        errors.append(f"{file_path}: Line {i+1}: Inconsistent spacing around operator '{op}'")

                # Enforce snake_case naming conventions for variables and functions
                # Regex to match camelCase names
                if re.search(r'\b[A-Z][a-zA-Z0-9]*\b', line):
                    errors.append(f"{file_path}: Line {i+1}: Use snake_case naming convention for variables and functions")

                # Check for braces on the same line as control structure
                if re.search(r'\b(if|else|for|while|do)\b\s*\(', line) and not re.search(r'{\s*$', line):
                    errors.append(f"{file_path}: Line {i+1}: Braces should be on the same line as control structure")

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
        print("Usage: python code_formatter_linter.py <directory>")
        sys.exit(1)

    target = sys.argv[1]
    if not os.path.isdir(target):
        print("Invalid directory.")
        sys.exit(1)

    # Create and configure linter
    linter = CodeFormatterLinter()
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
        print("No formatting issues found.")