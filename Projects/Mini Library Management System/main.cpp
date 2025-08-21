#include <iostream>
#include <vector>
#include "book.h"
#include "utils.h"

using namespace std;

// Predefined dataset in vector
vector<Book> library = {
    {1, "The C++ Programming Language", "Bjarne Stroustrup", 2013},
    {2, "Effective Modern C++", "Scott Meyers", 2014},
    {3, "Clean Code", "Robert C. Martin", 2008},
    {4, "Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", 1994},
    {5, "Introduction to Algorithms", "Thomas H. Cormen", 2009}};


int main()
{
    int choice;
    do
    {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search by id\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(library);
            break;
        case 2:
            displayBooks(library);
            break;
        case 3:
        {
            int id;
            cout << "Search by id: ";
            cin >> id;
            int idx = linearSearch(library, id);
            if (idx != -1)
                cout << "Title: " << library[idx].title << " by: " << library[idx].author << "\n";
            else
                cout << "Not found\n";
            break;
        }
        case 4:
            cout << "Good bye\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
