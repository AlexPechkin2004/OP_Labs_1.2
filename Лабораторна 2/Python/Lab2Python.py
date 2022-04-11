from functions import *

first_file_path = "first file.txt"
second_file_path = "second file.txt"
input_file(first_file_path)

print("First file:")
output_file(first_file_path)

print("\nBirthday in this month and work experience equals or more than 5 years: ")
birthday_in_this_month(first_file_path)
print()

create_second_file(first_file_path, second_file_path)
print("Started career in 25 y.o. or less, and work experience equals or more than 10 years (second file):")
output_file(second_file_path)