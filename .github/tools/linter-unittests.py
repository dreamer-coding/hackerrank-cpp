import os
import re
import logging
from threading import Thread, Lock
from queue import Queue
import ast

class TestAnalyzer:
    def __init__(self, test_directory="test/", source_directory="code/", num_threads=4):
        self.test_directory = test_directory
        self.source_directory = source_directory
        self.num_threads = num_threads
        self.test_cases = set()
        self.source_functions = set()
        self.recommendations = {}
        self.lock = Lock()
        self.logger = self.setup_logger()

    def setup_logger(self):
        logger = logging.getLogger("TestAnalyzer")
        logger.setLevel(logging.INFO)
        formatter = logging.Formatter("%(asctime)s - %(levelname)s - %(message)s")
        stream_handler = logging.StreamHandler()
        stream_handler.setFormatter(formatter)
        logger.addHandler(stream_handler)
        return logger

    def extract_test_cases(self):
        try:
            test_files = [file for file in os.listdir(self.test_directory) if file.startswith("xtest_")]

            for file in test_files:
                file_path = os.path.join(self.test_directory, file)
                with open(file_path, 'r') as f:
                    lines = f.readlines()
                    for line in lines:
                        match = re.match(r'XTEST\((.*)\)', line.strip())
                        if match:
                            with self.lock:
                                self.test_cases.add(match.group(1))
        except Exception as e:
            self.logger.error(f"Error occurred while extracting test cases: {e}")

    def analyze_source_code(self):
        try:
            source_files = [file for file in os.listdir(self.source_directory) if file.endswith(".c") or file.endswith(".cpp")]

            for file in source_files:
                file_path = os.path.join(self.source_directory, file)
                with open(file_path, 'r') as f:
                    lines = f.readlines()
                    for line in lines:
                        match = re.match(r'\b(?:void|int|double|float|char)\s+(\w+)\s*\(', line.strip())
                        if match:
                            with self.lock:
                                self.source_functions.add((match.group(1), file_path))
        except Exception as e:
            self.logger.error(f"Error occurred while analyzing source code: {e}")

    def analyze_function_logic(self, function_name, file_path):
        try:
            with open(file_path, 'r') as f:
                code = f.read()

            tree = ast.parse(code)

            for node in ast.walk(tree):
                if isinstance(node, ast.FunctionDef) and node.name == function_name:
                    test_cases = set()
                    for subnode in ast.walk(node):
                        if isinstance(subnode, ast.If):
                            condition = astor.to_source(subnode.test).strip()
                            test_cases.add(condition)
                    return test_cases

        except Exception as e:
            self.logger.error(f"Error occurred while analyzing function logic for {function_name}: {e}")

    def generate_recommendations(self):
        try:
            for function, file_path in self.source_functions:
                if function not in self.test_cases:
                    test_cases = self.analyze_function_logic(function, file_path)
                    if test_cases:
                        with self.lock:
                            self.recommendations[function] = test_cases
        except Exception as e:
            self.logger.error(f"Error occurred while generating recommendations: {e}")

    def process(self):
        threads = []
        queue = Queue()

        # Worker function
        def worker():
            while True:
                func = queue.get()
                if func is None:
                    break
                func()
                queue.task_done()

        # Start worker threads
        for _ in range(self.num_threads):
            thread = Thread(target=worker)
            thread.start()
            threads.append(thread)

        # Queue tasks
        queue.put(self.extract_test_cases)
        queue.put(self.analyze_source_code)

        # Wait for all tasks to complete
        queue.join()

        # Stop workers
        for _ in range(self.num_threads):
            queue.put(None)
        for thread in threads:
            thread.join()

        # Generate recommendations
        self.generate_recommendations()

if __name__ == "__main__":
    analyzer = TestAnalyzer()
    analyzer.process()

    if analyzer.recommendations:
        print("Recommendations for test cases:")
        for function, test_cases in analyzer.recommendations.items():
            print(f"- Function: {function}")
            print("  Test Cases:")
            for test_case in test_cases:
                print(f"    - {test_case}")
    else:
        print("No recommendations. All functions are covered by existing test cases.")
