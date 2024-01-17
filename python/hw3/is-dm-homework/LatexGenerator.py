import io
import os
import random

class LatexGenerator:
  def __init__(self, random_seed: int, template_files: dict):
    self.random_seed = random_seed
    self.template_files = template_files
    self.templates = {}
    self.tasks = None
    self.students = None
  
  
  def read_templates(self, template_dir: str) -> None:
    for key, template_file in self.template_files.items():
      template_content = self.read_file(f'{template_dir}/{template_file}')
      self.templates[key] = template_content
  
 
  def read_students(self, file_name: str) -> None:
    with io.open(f"{file_name}", encoding='utf-8') as file:
      text = file.readlines()
      self.students = text
  
  def read_tasks(self, tasks_dir: str) -> None:
    self.tasks = []
    total_tasks = len(os.listdir(f"{tasks_dir}"))
    print(total_tasks)
    for i in range(1, total_tasks + 1):
      self.tasks.append([])
      total_variants = len(os.listdir(f'{tasks_dir}/{i}'))
      for k in range(1, total_variants + 1):
        self.tasks[i - 1].append(self.read_file(f'{tasks_dir}/{i}/{k}.tex'))
        
        
  @staticmethod
  def generate_variant(counts) -> tuple:
    return tuple(random.randint(1, count) for count in counts)
  
  
  def generate_variants(self, total) -> list[set]:
    counts = [len(task) for task in self.tasks]
    result = set()
    random.seed(self.random_seed)
    while len(result) < total:
      result.add(self.generate_variant(counts))
    return list(result)
  
  
  def make_tex_file(self, 
                    filename: str, 
                    iterable, 
                    variants=None, 
                    q_start='', 
                    q_start2='', 
                    q_finish='', 
                    head='', 
                    tail='') -> None:
    with io.open(filename, "w", encoding='utf-8') as out:
      print(f"Making {filename} file...")

      out.write(head)
      for i, item in enumerate(iterable):
        out.write(q_start + str(item) + q_start2)
        if variants:
          for task_number, task in enumerate(self.tasks):
            out.write(task[variants[i][task_number] - 1])
        else:
          for _, task in enumerate(self.tasks[i]):
            out.write(task)
        out.write(q_finish)

      out.write(tail)
      
  @staticmethod
  def read_file(name):
    with io.open(name, encoding="utf-8") as file:
      text = file.read()
    return text
  
  def generate_latex_files(self, 
                           tasks_folder: str,  
                           students_file: str,
                           templates_folder : str,
                           output_dir : str="latex", 
                           main_filename : str="main.tex", 
                           dump_filename : str="dump.tex"): 
    
    random.seed(self.random_seed)
    
    self.read_students(students_file)
    self.read_templates(templates_folder)
    self.read_tasks(tasks_folder)
    
    os.makedirs(output_dir, exist_ok=True)
    variants = self.generate_variants(len(self.students))
    random.shuffle(variants)
    
    self.make_tex_file(
      os.path.join(output_dir, main_filename),
      self.students,
      variants,
      head=self.templates['head'],
      q_start=self.templates['q_start'],
      q_start2=self.templates['q_start2'],
      q_finish=self.templates['q_finish'],
      tail=self.templates['tail']
    )
    self.make_tex_file(
      os.path.join(output_dir, dump_filename),
      range(1, len(self.tasks) + 1),
      q_start=self.templates['q_start'],
      q_start2=self.templates['q_start2'],
      q_finish=self.templates['q_finish'],
      tail=self.templates['tail']
    )
    
    print("Done!")