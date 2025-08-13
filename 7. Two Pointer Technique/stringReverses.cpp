#include <bits/stdc++.h>

using namespace std;

string reverses(string str)
{
    int n = str.size();

    // Initialize the two pointer are tow corners
    int start = 0;
    int end = n - 1;

    // Movies both pointer to each other
    while (start < end)
    {
        if (str[start] == ' ')
        {
            start++;
            continue;
        }
        else if (str[end] == ' ')
        {
            end--;
            continue;
        }
        else
        {
            // both are not spaced then swap
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }
    return str;
}

int main()
{
    string s = "We are learning data structure and algorithms";
    cout << reverses(s) << endl;
    return 0;
}