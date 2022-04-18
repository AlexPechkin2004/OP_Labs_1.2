#include "Header.h"

int main()
{
    Book* array_of_books;
    int books_count, min_year, max_year;
    cout << "Enter how many books you want to store: ";
    cin >> books_count;
    array_of_books = CreateArray(books_count);
    ArrayOutput(array_of_books, books_count);
    cout << "\n\nEnter min year of range: ";
    cin >> min_year;
    cout << "Enter max year of range: ";
    cin >> max_year;
    TheThickestBook(array_of_books, books_count, min_year, max_year);
}