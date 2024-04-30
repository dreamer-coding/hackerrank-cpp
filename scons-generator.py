import os

class SConsScriptGenerator:
    def __init__(self, project_name='YourProject'):
        self.project_name = project_name

    def generate_build_script(self):
        script_content = """
import os
from SCons.Script import Environment, Glob, Default

env = Environment(CC='gcc', CXX='g++', CFLAGS=['-std=c2x'], CXXFLAGS=['-std=c++20', '-Werror'], tools=[])

solutions_dir = 'solutions'
solutions = [os.path.splitext(f)[0] for f in os.listdir(solutions_dir) if f.endswith('.cpp')]

programs = []
for solution in solutions:
    target = os.path.join('bin', solution)  # Target executable path
    source = os.path.join(solutions_dir, f"{solution}.cpp")  # Source file path
    program = env.Program(target=target, source=source)
    programs.append(program)

Default(programs)  # Set the default target to be all the programs
"""
        with open('SConstruct', 'w') as file:
            file.write(script_content)


if __name__ == "__main__":
    scons_generator = SConsScriptGenerator(project_name='Hacker Rank')
    scons_generator.generate_build_script()
