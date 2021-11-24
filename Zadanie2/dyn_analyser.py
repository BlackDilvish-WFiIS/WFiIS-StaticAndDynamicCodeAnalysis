import sys
import os

variables = []
functions = []
supported_types = ['int', 'float']
supported_operations = ['=', '+=', '*=']

def isFunctionDefinition(args):
    return args[0] in supported_types and '()' in line

def isVariableDeclaration(args):
    return args[0] in supported_types and ';' in line

def isVariableModification(args):
    vars = [v for var in variables for v in var]
    return len(list(set(vars) & set(args))) > 0 and len(list(set(supported_operations) & set(args))) > 0

def isReturn(args):
    return 'return' in args

if __name__ == "__main__":
    filename = sys.argv[1]
    newfilename = "new" + filename

    with open(filename, 'r') as f:
        lines = f.read().splitlines()

    for i, line in enumerate(lines):
        args = line.split()
        if len(args) > 0:
            if isFunctionDefinition(args):
                lines[i] = line + f'printf("Wejscie do funkcji:{line[:-2]}\\n");'
                variables.append([])
                functions.append(line[:-2])
            if isVariableDeclaration(args):
                lines[i] = line + f'printf("Stworzenie zmiennej:{line}\\n");'
                var = line.split()[1]
                if var[len(var)-1] == ';':
                    var = var[:-1]
                variables[len(variables)-1].append(var)
                continue
            if isVariableModification(args):
                vars = [v for var in variables for v in var]
                var = list(set(vars) & set(args))[0]
                lines[i] = line + f'printf("Zmiana zmiennej: {var}=%g\\n", {var});'
            if isReturn(args):
                aa = ''.join(f'{v},' for v in variables[len(variables)-1])
                aa = aa[:-1] + ');'
                lines[i] = f'printf("Wyjscie z funkcji \\"%s\\". Stan zmiennych: ' + ''.join([f'{v}=%g, ' for v in variables[len(variables)-1]]) + '\\n",' + f'"{functions.pop()}",' + aa + line
                variables.pop()

    with open(newfilename, 'w') as f:
        f.write('\n'.join([line for line in lines]))

    os.system('gcc ' + newfilename)
    os.system('.\\a.exe')
