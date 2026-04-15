#pragma once
#include <string>
using namespace std;

class Book
{
    string title;
    string author;
    string ISBN;

public:
    inline static int counter = 0;

    Book(string in_title, string in_author, string in_ISBN);
    ~Book();

    string get_title();

    string get_author();

    string get_ISBN();
};

class Library
{
    Book* Shelf[100];

public:
    Library();

    void add_book(Book* booky);

    void remove_book(string ISBN);

    void search_book(string ISBN);
};
