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

class Fixer:
    def __init__(self, skip_plugin=None):
        self.skip_plugin = skip_plugin

    def fix_file(self, file_path):
        if self.skip_plugin and self.skip_plugin.should_skip(file_path):
            return
        with open(file_path, 'r') as file:
            lines = file.readlines()

        fixed_lines = []
        for i, line in enumerate(lines):
            # Fix trailing whitespace
            line = re.sub(r'\s+$', '', line)

            # Add missing semicolons
            if not line.strip().endswith(';') and not line.strip().startswith('#') and line.strip() != '':
                line = line.rstrip() + ';'

            # Convert tabs to spaces
            line = line.replace('\t', '    ')

            # Fix inconsistent spacing around operators
            operators = ['+', '-', '*', '/', '=', '==', '!=', '<', '>', '<=', '>=']
            for op in operators:
                line = re.sub(fr'\s*{op}\s*', f' {op} ', line)

            # Check line length
            if len(line.rstrip()) > 80:
                # For simplicity, let's just split the line at the 80th character
                line = line[:80] + '\\\n' + line[80:]

            # Fix braces on the same line as control structure
            if re.search(r'\b(?:if|else|for|while|do)\b', line) and not re.search(r'{\s*$', line):
                line = re.sub(r'(\b(?:if|else|for|while|do)\b.*)(\n\s*)', r'\1 {\2', line)

            fixed_lines.append(line)

        with open(file_path, 'w') as file:
            file.writelines(fixed_lines)

    def fix_directory(self, directory):
        for root, _, files in os.walk(directory):
            for file in files:
                if file.endswith(('.c', '.cpp', '.h', '.hpp', '.m', '.mm', '.cu', '.cuh')):
                    file_path = os.path.join(root, file)
                    self.fix_file(file_path)

    def fix_concurrently(self, directory, num_threads=4):
        queue = Queue()

        def worker():
            while True:
                file_path = queue.get()
                if file_path is None:
                    break
                self.fix_file(file_path)
                queue.task_done()

        threads = []
        for _ in range(num_threads):
            thread = Thread(target=worker)
            thread.start()
            threads.append(thread)

        for root, _, files in os.walk(directory):
            for file in files:
                if file.endswith(('.c', '.cpp', '.h', '.hpp', '.m', '.mm', '.cu', '.cuh')):
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
        print("Usage: python code-format.py <directory>")
        sys.exit(1)

    target = sys.argv[1]
    if not os.path.isdir(target):
        print("Invalid directory.")
        sys.exit(1)

    # Create and configure fixer
    fixer = Fixer()
    skip_plugin = SkipPlugin()
    skip_plugin.add_skip("subprojects/")  # Skip third-party libraries
    fixer.skip_plugin = skip_plugin

    # Perform fixing
    fixer.fix_concurrently(target)

    print("All files fixed.")
