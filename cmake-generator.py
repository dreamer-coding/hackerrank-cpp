import os

class CMakeScriptGenerator:
    def __init__(self, project_name='YourProject'):
        self.project_name = project_name

    def generate_source_build_script(self):
        source_script = f"""
cmake_minimum_required(VERSION 3.0)
project({self.project_name} LANGUAGES CXX)

add_subdirectory(solutions)
        """
        with open('CMakeLists.txt', 'w') as file:
            file.write(source_script)

    def generate_subdirectory_build_script(self):
        solutions_dir = 'solutions'
        solutions = [os.path.splitext(f)[0] for f in os.listdir(solutions_dir) if f.endswith('.cpp')]
        solved = len(solutions)
    
        subdirectory_script = f"""
set(solutions {solutions})
set(solved {solved})

if(solved >= 10)
    set(index_str "_0")
else()
    set(index_str "_0[0:1]")
endif()

foreach(iter RANGE ${solved})
    list(GET solutions ${iter} name)
    add_executable(prog-${{index_str}}${{iter+1}} ${name}.cpp)
endforeach()
        """
        with open(os.path.join(solutions_dir, 'CMakeLists.txt'), 'w') as file:
            file.write(subdirectory_script)


if __name__ == "__main__":
    cmake_generator = CMakeScriptGenerator(project_name='Hacker Rank')
    cmake_generator.generate_source_build_script()
    cmake_generator.generate_subdirectory_build_script()
