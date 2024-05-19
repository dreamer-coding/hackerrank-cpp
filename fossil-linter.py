import re
import sys
import os
from threading import Thread
from queue import Queue

class Linter:
    def __init__(self, ignore_patterns=None):
        self.errors = []
        self.ignore_patterns = ignore_patterns or []

    def lint_file(self, file_path):
        errors = []
        with open(file_path, 'r') as file:
            lines = file.readlines()
            for i, line in enumerate(lines):
                # Check for trailing whitespace, missing semicolon, indentation, etc.
                # (Same as before)
                pass

        self.errors.extend(errors)

    def lint_directory(self, directory):
        for root, _, files in os.walk(directory):
            for file in files:
                if file.endswith(('.c', '.cpp', '.h', '.hpp', '.m', '.mm')):
                    file_path = os.path.join(root, file)
                    if not self._should_ignore(file_path):
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
                    if not self._should_ignore(file_path):
                        queue.put(file_path)

        queue.join()

        # Stop workers
        for _ in range(num_threads):
            queue.put(None)
        for thread in threads:
            thread.join()

    def _should_ignore(self, file_path):
        for pattern in self.ignore_patterns:
            if re.search(pattern, file_path):
                return True
        return False

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python linter.py <directory>")
        sys.exit(1)

    target = sys.argv[1]
    if not os.path.isdir(target):
        print("Invalid directory.")
        sys.exit(1)

    # Define patterns to ignore
    ignore_patterns = [
        r'/third_party/',  # Example: Ignore third-party libraries
        r'\.generated\.',  # Example: Ignore generated code files
    ]

    linter = Linter(ignore_patterns=ignore_patterns)
    linter.lint_concurrently(target)

    if linter.errors:
        for error in linter.errors:
            print(error)
        sys.exit(1)
    else:
        print("No errors found.")
