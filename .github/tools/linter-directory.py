import os
import re
import concurrent.futures

class LinterProject:
    def __init__(self, directory, ignore_dirs=None, num_threads=4):
        self.directory = directory
        self.ignore_dirs = ignore_dirs or []
        self.num_threads = num_threads
        self.build_files = ['Makefile', 'makefile', 'BUILD', 'WORKSPACE', 'CMakeLists.txt']
        self.language_extensions = ['.c', '.h', '.cpp', '.hpp', '.m', '.mm', '.cu', '.py', '.pyx']
        self.issues = []

    def lint_file(self, file_path):
        file_name = os.path.basename(file_path)
        file_extension = os.path.splitext(file_name)[1]

        if file_name in self.build_files:
            self.issues.append(f"Build file found: {file_path}")

        if file_extension not in self.language_extensions:
            self.issues.append(f"Invalid file extension: {file_path}")

    def lint_directory(self, directory):
        for root, dirs, files in os.walk(directory):
            dirs[:] = [d for d in dirs if d not in self.ignore_dirs]
            for file in files:
                file_path = os.path.join(root, file)
                self.lint_file(file_path)

    def lint_concurrently(self):
        with concurrent.futures.ThreadPoolExecutor(max_workers=self.num_threads) as executor:
            future_to_file = {executor.submit(self.lint_file, file_path): file_path
                              for root, _, files in os.walk(self.directory) for file_path in [os.path.join(root, file) for file in files]}
            for future in concurrent.futures.as_completed(future_to_file):
                file_path = future_to_file[future]
                try:
                    future.result()
                except Exception as exc:
                    self.issues.append(f"Error linting {file_path}: {exc}")

    def lint(self):
        if self.num_threads > 1:
            self.lint_concurrently()
        else:
            self.lint_directory(self.directory)

if __name__ == "__main__":
    directory_to_lint = "your_directory_path_here"
    ignore_dirs = ["subprojects", "builddir"]
    linter = LinterProject(directory_to_lint, ignore_dirs=ignore_dirs)
    linter.lint()

    if linter.issues:
        print("Linting issues found:")
        for issue in linter.issues:
            print(issue)
    else:
        print("No linting issues found.")
