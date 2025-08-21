#include "utils.h"
#include <iostream>

void addBook(vector<Book> &library)
{
    Book b;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter Year: ";
    cin >> b.year;

    library.push_back(b);
    cout << "Book added successfully!\n";
}


void displayBooks(vector<Book> &library)
{
     cout << "Library Collection:\n";
    for (const auto& book : library) {
        cout << "ID: " << book.id
             << " | Title: " << book.title
             << " | Author: " << book.author
             << " | Year: " << book.year
             << endl;
    }
}


int linearSearch(vector<Book>& library, int id) {
    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == id)
            return i;
    }
    return -1;
}
