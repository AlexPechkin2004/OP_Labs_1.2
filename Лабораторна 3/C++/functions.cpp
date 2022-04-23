#include "Header.h"

void Book::setAuthor(string author_value)
{
    author = author_value;
}

void Book::setName(string name_value)
{
    name = name_value;
}

void Book::setYear(int year_value)
{
    year = year_value;
}

void Book::setPages(int pages_value)
{
    pages = pages_value;
}


string Book::getAuthor()
{
    return author;
}

string Book::getName()
{
    return name;
}

int Book::getYear()
{
    return year;
}

int Book::getPages()
{
    return pages;
}



Book* CreateArray(int count)
{
    int year_value, pages_value;
    string author_value, name_value;

    Book* array = new Book[count];
    cin.ignore();
    for (int i = 0; i < count; i++) {
        Book book;

        cout << "\nEnter author's name: ";
        getline(cin, author_value);
        book.setAuthor(author_value);

        cout << "Enter bookname: ";
        getline(cin, name_value);
        book.setName(name_value);

        cout << "Enter year: ";
        cin >> year_value;
        book.setYear(year_value);
        cin.ignore();

        cout << "Enter pages: ";
        cin >> pages_value;
        book.setPages(pages_value);
        cin.ignore();

        array[i] = book;
    }
    return array;
}

void ArrayOutput(Book* array, int count)
{
    cout << "\nYour books: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "\n\nBook " << i + 1 << ": ";
        cout << "\nAuthor's name: ";
        cout << array[i].getAuthor();
        cout << "\nBookname: ";
        cout << array[i].getName();
        cout << "\nYear: ";
        cout << array[i].getYear();
        cout << "\nPages: ";
        cout << array[i].getPages();
    }
}

void TheThickestBook(Book* array, int count, int min_year, int max_year)
{
    int the_thickest_book = 0;
    int temp_pages = 0;
    for (int i = 0; i < count; i++)
    {
        if (array[i].getYear() >= min_year && array[i].getYear() <= max_year)
        {
            if (array[i].getPages() > temp_pages)
            {
                temp_pages = array[i].getPages();
                the_thickest_book = i + 1;
            }
        }
    }

    if (the_thickest_book == 0)
    {
        cout << "\nThere's no books in selected range";
    }
    else
    {
        cout << "\nThe thickest book in selected range is Book " << the_thickest_book << endl;

        cout << "\nAuthor's name: ";
        cout << array[the_thickest_book - 1].getAuthor();
        cout << "\nBookname: ";
        cout << array[the_thickest_book - 1].getName();
        cout << "\nYear: ";
        cout << array[the_thickest_book - 1].getYear();
        cout << "\nPages: ";
        cout << array[the_thickest_book - 1].getPages();
    }
}
