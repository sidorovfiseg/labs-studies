import io, os, itertools, random

def main():
    random.seed(1183)
    print("Reading templates...")
    head = readFile('templates/head.tex')
    qStart = readFile('templates/qStart.tex')
    qStart2 = readFile('templates/qStart2.tex')
    qFinish = readFile('templates/qFinish.tex')
    tail = readFile('templates/tail.tex')

    print("Reading tasks...")
    tasks = readTasks()

    print("Reading students...")
    students = readStudents()

    print("Generating variants...")
    variants = generateVariants(tasks, len(students))
    random.shuffle(variants)


    os.makedirs(os.path.dirname("latex/main.tex"), exist_ok=True)
    
    out = io.open("latex/main.tex", "w", encoding='utf-8')
    print("Making main.tex file...")

    out.write(head)
    for i in range(len(variants)):
        out.write(qStart + str(students[i]) + qStart2)
        for taskNumber, task in enumerate(tasks):
            out.write(task[variants[i][taskNumber]-1])    
        out.write(qFinish)
    out.write(tail)
    out.close()

    out = io.open("latex/dump.tex", "w", encoding='utf-8')
    print("Making dump.tex file...")

    out.write(head)
    for i in range(len(tasks)):
        out.write(qStart + str(i+1) + qStart2)
        for k in range(len(tasks[i])):
            out.write(tasks[i][k])
        out.write(qFinish)
    out.write(tail)
    out.close()

    print("Done!")
    
# Чтение заданий из папки заданий, возвращение двумерного массива с результатом чтения
# Переделан форматированный ввод
def readTasks():
    result = []
    totalTasks = len(os.listdir('tasks'))
    print(totalTasks)
    for i in range(0,totalTasks):
        result.append([])
        totalVariants = len(os.listdir(f'tasks/{i + 1}'))
        for k in range(0,totalVariants):
            result[i].append(readFile(f'tasks/{i + 1}/{k + 1}.tex'))
    return result

def readDir(dirName):
    result = []
    subdirs = os.listdir(dirName)
    for i in range(len(subdirs)):
        result.append([])
        subdir_files = os.listdir(f'{dirName}/{subdirs[i]}')
        for j in range(len(subdir_files)):
            result[i].append(readFile(f'{dirName}/{subdirs[i]}/{subdir_files[j]}.tex'))
    return result
    

# Чтение списка студентов, возвращение массива студентов
def readStudents():
    file = io.open("students.txt", encoding='utf-8')
    result = file.readlines()
    file.close()
    return result

def generateVariants(tasks, total):
    counts = []
    for i in tasks:
        counts.append(len(i))
    result = set()
    while len(result) < total:
        result.add(generateVariant(counts))
    return list(result)

def generateVariant(counts):
    result = []
    for i in range(len(counts)):
        result.append(random.randint(1,counts[i]))
    return tuple(result)

# Чтение файла и возвращение содержимого
def readFile(name):
    file = io.open(name, encoding='utf-8')
    text = file.read()
    file.close()
    return text


if __name__ == "__main__":
    main()
