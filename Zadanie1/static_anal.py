import re
from typing import List, Dict

regex_types: Dict = {
    'int': "^\s*[a-z]+\s[a-z]+\s=\s\d;", 
    'double': "^\s*[a-z]+\s[a-z]+\s=\s\d.\d;", 
    'char': "^\s*[a-z]+\s[a-z]+\s=\s'.{1}';"
    }
allowed_eol_chars: List = ['>', '{', '}']
allowed_start_chars: List = ['//', '/*']


class StaticAnalisisTool:

    def __init__(self, filepath):
        with open(filepath, 'r') as f:
            self.file_content: List = f.readlines()
        self.file_str: str = ''.join(self.file_content)
        self.error_count: int = 0

    def analyze_file(self):
        print('Running static analysis tool...')
        self.check_missing_semicolons()
        self.check_variable_types()
        self.check_misssing_brackets()
        print(f"Found {self.error_count} errors")

    def check_misssing_brackets(self) -> bool:
        brackets = ''.join( [i for i in self.file_str if i in '{}[]()'] )
        while len(brackets):
            new_brackets = brackets.replace( '()', '').replace( '{}', '').replace( '[]', '')
            if brackets == new_brackets: 
                break
            brackets = new_brackets
        if len(brackets):
            self.error_count += len(brackets)
            return not print(f'Found loose brackets - {brackets}')
        return True
    
    def check_variable_types(self) -> bool:
        for line_no, line_text in enumerate(self.file_content):

            for var_type, expression in regex_types.items():
                if re.search(f"{expression}", line_text):
                    word_list = list(filter(lambda item: item, line_text.split(' ')))
                    if word_list[0] != var_type:
                        self.error_count += 1
                        print(f"Line: {line_no}: typing error, got '{word_list[0]}' instead of '{var_type}'")
        
    def check_missing_semicolons(self) -> bool:

        for line_no, line_text in enumerate(self.file_content):
            line_text = line_text.replace(' ', '')
            line_text = line_text.replace('\n', '')
            
            if len(line_text) and (line_text[-1] not in allowed_eol_chars) and (line_text[-1] != ';') \
                and (line_text[0:2] not in allowed_start_chars):
                print(f"Line {line_no}: missing semicolon")

    
if __name__ == '__main__':
    tool = StaticAnalisisTool('main.c')
    tool.analyze_file()
