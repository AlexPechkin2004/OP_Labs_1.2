#include "Header.h"

int main()
{
    string first_file_path = "first file.txt";
    string second_file_path = "second file.txt";
    input_file(first_file_path);

    cout << "\nFirst file:\n";
    output_file(first_file_path);

    cout << "\nBirthday in this month and work experience equals or more than 5 years: " << endl;
    birthday_in_this_month(first_file_path);
    cout << endl;

    create_second_file(first_file_path, second_file_path);

    cout << "\nStarted career in 25 y.o. or less, and work experience equals or more than 10 years (second file):" << endl;
    output_file(second_file_path);

    return 0;
}