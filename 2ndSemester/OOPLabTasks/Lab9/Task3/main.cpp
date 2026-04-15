#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

int main()
{
    //making library
    Library fastLibrary;

    //making some objects
    Book* b1 = new Book("The C++ Programming Language", "Bjarne Stroustrup", "123");
    Book* b2 = new Book("Clean Code", "Robert C. Martin", "198");
    Book* b3 = new Book("Design Patterns", "Gang of Four", "145");

    //adding books
    cout << endl;
    fastLibrary.add_book(b1);
    fastLibrary.add_book(b2);
    fastLibrary.add_book(b3);

    //searching book
    cout << endl;
    fastLibrary.search_book("198");

    //removing book
    cout << endl;
    fastLibrary.remove_book("198");

    //searching for removed book
    cout << endl;
    fastLibrary.search_book("198");

    //cleaning
    delete b1;
    delete b2;
    delete b3;

    return 0;
}
