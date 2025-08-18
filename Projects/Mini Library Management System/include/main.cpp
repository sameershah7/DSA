#include <iostream>
#include <vector>
#include "../src/book.h"
using namespace std;

vector<Book> library; // storage for books

void addBook()
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

void displayBooks()
{
    cout << "\nLibrary Collection:\n";
    for (auto &b : library)
    {
        cout << b.id << " | " << b.title << " | " << b.author << " | " << b.year << "\n";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            cout << "Good bye ";
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
