#include "Header.h"

int main()
{
	string first_file_name = "original file.txt";
	string second_file_name = "modified file.txt";
	
	input_file(first_file_name);
	cout << "\nOriginal file:\n";
	output_file(first_file_name);

	create_second_file(first_file_name, second_file_name);
	cout << "Modified file:\n";
	output_file(second_file_name);
}