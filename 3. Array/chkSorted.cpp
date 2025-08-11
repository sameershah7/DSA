#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isSortedHelper(vector<int> &arr, int n)
{
    // Recursive approach - O(n) Time and O(n) Space
    if (n == 0 || n == 1)
    {
        return true;
    }
    return arr[n - 1] >= arr[n - 2] && isSortedHelper(arr, n - 1);
}

bool isSorted(vector<int> &arr)
{
    // return isSortedHelper(arr, arr.size());

    // using for loop
    // Iterative approach - O(n) Time and O(1) Space
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i - 1] > arr[i])
    //     {
    //         return false;
    //     }
    // }
    // return true;

    // is_sorted() is a built-in method
    //Using Built-in Methods - O(n) Time and O(1) Space
    if (is_sorted(arr.begin(), arr.end()))
    {
        return true;
    }

    return false;
}

int main()
{
    vector<int> arr = {10, 20,  30, 40, 50};
    cout << arr[-1] << "" << endl;
    cout << isSorted(arr);
    return 0;
}