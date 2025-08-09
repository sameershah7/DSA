#include <iostream>
#include <vector>
using namespace std;

// Function to rearrange the array such that arr[i] = i.
void modifyArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n, -1);
    // pass values: {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};

    // temp va: {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // 0 loop = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // 1 loop = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // 2 loop = {-1, -1, -1, -1, -1, -1,  6, -1, -1, -1};
    // 3 loop = {-1,  1, -1, -1, -1, -1, -1, -1, -1, -1};
    // 4 loop = {-1, -1, -1, -1, -1, -1, -1, -1, -1,  9};
    // 5 loop = {-1, -1, -1,  3, -1, -1, -1, -1, -1, -1};
    // 6 loop = {-1, -1,  2, -1, -1, -1, -1, -1, -1, -1};
    // 7 loop = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // 8 loop = {-1, -1, -1, -1,  4, -1, -1, -1, -1, -1};
    // 9 loop = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // ------------------------------------------------
    // final r= {-1,  1,  2,  3,  4, -1,  6,  -1, -1, 9 }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            temp[arr[i]] = arr[i];
        }
    }

    // Update the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    vector<int> arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    modifyArray(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}