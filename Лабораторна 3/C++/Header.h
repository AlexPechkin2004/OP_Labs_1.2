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
    void setAuthor(string author_value);
    void setName(string name_value);
    void setYear(int year_value);
    void setPages(int pages_value);

    string getAuthor();
    string getName();
    int getYear();
    int getPages();
};

Book* CreateArray(int);
void ArrayOutput(Book*, int);
void TheThickestBook(Book*, int, int, int);
