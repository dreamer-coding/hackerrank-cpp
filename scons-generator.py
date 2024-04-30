import os

class SConsScriptGenerator:
    def __init__(self, project_name='YourProject'):
        self.project_name = project_name

    def generate_source_build_script(self):
        source_script = f"""
env = Environment(CC='gcc', CXX='g++', CFLAGS=['-std=c2x'], CXXFLAGS=['-std=c++20', '-Werror'], tools=[])

Program('main', Glob('*.cpp'))
Default('main')
        """
        with open('SConstruct', 'w') as file:
            file.write(source_script)

    def generate_subdirectory_build_script(self):
        solutions_dir = 'solutions'
        solutions = [os.path.splitext(f)[0] for f in os.listdir(solutions_dir) if f.endswith('.cpp')]
        solved = len(solutions)
    
        subdirectory_script = f"""
env = Environment(CC='gcc', CXX='g++', CFLAGS=['-std=c2x'], CXXFLAGS=['-std=c++20', '-Werror'], tools=[])

solutions = {solutions}
solved = {solved}

for solution in solutions:
    Program(target=solution, source=solution + '.cpp')
        """
        with open(os.path.join(solutions_dir, 'SConscript'), 'w') as file:
            file.write(subdirectory_script)


if __name__ == "__main__":
    scons_generator = SConsScriptGenerator(project_name='Hacker Rank')
    scons_generator.generate_source_build_script()
    scons_generator.generate_subdirectory_build_script()
