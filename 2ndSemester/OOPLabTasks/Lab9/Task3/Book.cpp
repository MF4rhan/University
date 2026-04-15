#include "Book.h"
#include <string>
#include <iostream>

    Book::Book(string in_title, string in_author, string in_ISBN)
    : title(in_title), author(in_author), ISBN(in_ISBN)
    {
        Book::counter++;
    }

    Book::~Book()
    {
        Book::counter--;
    }

    string Book::get_title()
    {
        return title;
    }

    string Book::get_author()
    {
        return author;
    }

    string Book::get_ISBN()
    {
        return ISBN;
    }

    Library::Library()
    {
        for(int i = 0 ; i < 100 ; i++)
        {
            Shelf[i] = nullptr;
        }
    }

    void Library::add_book(Book* booky)
    {
        for(int i = 0 ; i < 100 ; i++)
        {
            if (Shelf[i] == nullptr)
            {
                Shelf[i] = booky;
                return;
            }
        }
    }

    void Library::remove_book(string ISBN)
    {
        for (int i = 0 ; i < Book::counter ; i++)
        {
            if (Shelf[i] != nullptr && Shelf[i]->get_ISBN() == ISBN)
            {
                Shelf[i] = nullptr;
                cout << "Book with ISBN: " << ISBN << " has been removed." << endl;
                return;
            }

            if (i == (Book::counter-1))
            {
                cout << "This book does not exist in the Library." << endl;
            }
        }
    }

    void Library::search_book(string ISBN)
    {
        for (int i = 0 ; i < Book::counter ; i++)
        {
            if (Shelf[i] != nullptr && Shelf[i]->get_ISBN() == ISBN)
            {
                cout << "Book Title: " << Shelf[i]->get_title() << endl;
                cout << "Book Author: " << Shelf[i]->get_author() << endl;
                cout << "Book ISBN: " << Shelf[i]->get_ISBN() << endl << endl;
                return;
            }

            if (i == (Book::counter-1))
            {
                cout << "This book does not exist in the Library." << endl;
            }
        }
    }
