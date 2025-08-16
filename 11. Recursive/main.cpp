//  What is Recursion?

// Recursion is a programming technique where a function calls itself directly or indirectly to solve a problem.

#include <bits/stdc++.h>
using namespace std;

void printFun(int test)
{
    if (test < 1)
        return;
    else
    {
        cout << test << " ";
        printFun(test - 1);
        cout << test << " ";
        return;
    }
}

int main()
{
    int test = 3;
    printFun(test);
}