from LatexGenerator import LatexGenerator

templates_files = {
    'head': 'head.tex',
    'q_start': 'qStart.tex',
    'q_start2': 'qStart2.tex',
    'q_finish': 'qFinish.tex',
    'tail': 'tail.tex'
}

templates_folder  = "templates"
tasks_folder = "tasks"
student_file = "students.txt"


if __name__ == "__main__":
    latex_generator = LatexGenerator(1183, templates_files)
    latex_generator.generate_latex_files(tasks_folder, student_file, templates_folder)