import os

class MesonScriptGenerator:
    def __init__(self, project_name='YourProject'):
        self.project_name = project_name

    def generate_source_build_script(self):
        source_script = f"""
project('{self.project_name}', 'cpp', default_options: ['c_std=c2x', 'cpp_std=c++20', 'werror=true', 'buildtype=minsize'])

subdir('solutions')
        """
        with open('meson.build', 'w') as file:
            file.write(source_script)

    def generate_subdirectory_build_script(self):
        solutions_dir = 'solutions'
        solutions = [os.path.splitext(f)[0] for f in os.listdir(solutions_dir) if f.endswith('.cpp')]
        solved = len(solutions)
    
        subdirectory_script = f"""
solutions = {solutions}
solved = {solved}

foreach iter : range(solved)
    name = solutions[iter]
    executable(name, name + '.cpp')
endforeach
        """
        with open(os.path.join(solutions_dir, 'meson.build'), 'w') as file:
            file.write(subdirectory_script)


if __name__ == "__main__":
    meson_generator = MesonScriptGenerator(project_name='Hacker Rank')
    meson_generator.generate_source_build_script()
    meson_generator.generate_subdirectory_build_script()
