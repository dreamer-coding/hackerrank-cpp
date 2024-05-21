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

class SecurityLinter:
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
                # Check for use of unsafe functions
                unsafe_functions = ['strcpy', 'strcat', 'sprintf', 'gets', 'scanf', 'printf']
                for func in unsafe_functions:
                    if re.search(fr'\b{func}\b', line):
                        errors.append(f"{file_path}: Line {i+1}: Use of unsafe function '{func}' detected")

                # Check for missing input validation (example: scanf without field width)
                if re.search(r'\bscanf\(\s*"[^"]*%\s*[^0-9][^"]*"\s*[,)]', line):
                    errors.append(f"{file_path}: Line {i+1}: Missing input validation in 'scanf'")

                # Check for improper use of memory functions
                if re.search(r'\bmemcpy\b', line) and not re.search(r'\bsizeof\b', line):
                    errors.append(f"{file_path}: Line {i+1}: Potential misuse of 'memcpy' without 'sizeof'")

                # Check for buffer overflows in sprintf
                if re.search(r'\bsprintf\s*\(.*\b%s\b', line):
                    errors.append(f"{file_path}: Line {i+1}: Potential buffer overflow in 'sprintf'")

                # Check for potential format string vulnerabilities in printf
                if re.search(r'\bprintf\s*\([^"]*$', line):
                    errors.append(f"{file_path}: Line {i+1}: Potential format string vulnerability in 'printf'")

                # Check for use of temporary files
                if re.search(r'\btmpnam\b|\btempnam\b', line):
                    errors.append(f"{file_path}: Line {i+1}: Use of insecure temporary file function detected")

                # Check for use of system calls
                if re.search(r'\bsystem\b', line):
                    errors.append(f"{file_path}: Line {i+1}: Use of 'system' function detected")

                # Check for null pointer dereference
                if re.search(r'\b\w+\s*=\s*NULL\s*;\s*\*\w+', line):
                    errors.append(f"{file_path}: Line {i+1}: Possible null pointer dereference")

                # Check for uninitialized variables (simple heuristic)
                if re.search(r'\bint\s+\w+;\s*\bif\b\s*\(\s*\w+\s*==\s*NULL\s*\)', line):
                    errors.append(f"{file_path}: Line {i+1}: Possible use of uninitialized variable")

                # Objective-C specific checks
                # Check for Objective-C insecure functions (example: performSelector:)
                if re.search(r'\bperformSelector\b', line):
                    errors.append(f"{file_path}: Line {i+1}: Use of 'performSelector' detected (potentially insecure)")

                # Check for Objective-C runtime function usage
                objc_runtime_functions = ['objc_msgSend', 'objc_getClass', 'objc_getMetaClass']
                for func in objc_runtime_functions:
                    if re.search(fr'\b{func}\b', line):
                        errors.append(f"{file_path}: Line {i+1}: Use of Objective-C runtime function '{func}' detected (ensure secure use)")

                # Check for @synchronized usage
                if re.search(r'\@synchronized\s*\(', line):
                    errors.append(f"{file_path}: Line {i+1}: Use of '@synchronized' detected (ensure proper usage to avoid deadlocks)")

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
        print("Usage: python security_linter.py <directory>")
        sys.exit(1)

    target = sys.argv[1]
    if not os.path.isdir(target):
        print("Invalid directory.")
        sys.exit(1)

    # Create and configure linter
    linter = SecurityLinter()
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
        print("No security vulnerabilities found.")