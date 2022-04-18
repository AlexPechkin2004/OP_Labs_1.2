#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string author, name;
    int year, pages;

public:
    void setAuthor(string author_value)
    {
        author = author_value;
    }

    void setName(string name_value)
    {
        name = name_value;
    }

    void setYear(int year_value)
    {
        year = year_value;
    }

    void setPages(int pages_value)
    {
        pages = pages_value;
    }


    string getAuthor()
    {
        return author;
    }

    string getName()
    {
        return name;
    }

    int getYear()
    {
        return year;
    }

    int getPages()
    {
        return pages;
    }
};

Book* CreateArray(int);
void ArrayOutput(Book*, int);
void TheThickestBook(Book*, int, int, int);