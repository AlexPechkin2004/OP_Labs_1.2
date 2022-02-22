from functions import *

first_file_name = "original file.txt"
second_file_name = "modified file.txt"

input_file(first_file_name)
print("\nOriginal file:")
output_file(first_file_name)

modify_file(first_file_name, second_file_name)
print("Modified file:")
output_file(second_file_name)