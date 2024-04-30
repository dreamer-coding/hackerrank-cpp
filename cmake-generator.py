import os

class CMakeScriptGenerator:
    def __init__(self, project_name='YourProject'):
        self.project_name = project_name

    def generate_root_cmake_file(self):
        root_script = (
            "cmake_minimum_required(VERSION 3.10)\n"
            f"project(\"{self.project_name}\" LANGUAGES CXX)\n\n"
            "set(CMAKE_CXX_STANDARD 20)\n"  # Setting C++20 standard
            "set(CMAKE_GENERATOR Ninja)\n"   # Setting Ninja as the generator
            "add_subdirectory(solutions)\n"
        )
        with open('CMakeLists.txt', 'w') as file:
            file.write(root_script)

    def generate_subdirectory_cmake_files(self):
        solutions_dir = 'solutions'
        solutions = [os.path.splitext(f)[0] for f in os.listdir(solutions_dir) if f.endswith('.cpp')]
        solved = len(solutions)
    
        subdirectory_script = (
            "set(solutions\n"
            "    " + ";\n    ".join(solutions) + "\n"
            ")\n\n"
            "foreach(solution ${solutions})\n"
            "    add_executable(${solution} ${solution}.cpp)\n"
            "endforeach()\n"
        )
        os.makedirs(solutions_dir, exist_ok=True)
        with open(os.path.join(solutions_dir, 'CMakeLists.txt'), 'w') as file:
            file.write(subdirectory_script)


if __name__ == "__main__":
    cmake_generator = CMakeScriptGenerator(project_name='Hacker Rank')
    cmake_generator.generate_root_cmake_file()
    cmake_generator.generate_subdirectory_cmake_files()
