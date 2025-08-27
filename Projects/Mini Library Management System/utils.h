#pragma once
#include <vector>
#include "book.h"
#include "utils.cpp"

using namespace std;

// Function declarations
void addBook(vector<Book> &library);
void displayBooks(vector<Book> &library);
int linearSearch(vector<Book> &library, int id);
void showLatestBooks(vector<Book> &library );