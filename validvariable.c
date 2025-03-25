import re

def is_valid_variable(name):
    return bool(re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', name))

variable_name = input("Enter a variable name: ")

if is_valid_variable(variable_name):
    print(f"{variable_name} is a valid variable name.")
else:
    print(f"{variable_name} is not a valid variable name.")
