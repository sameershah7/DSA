#include <iostream>
#include <vector>

using namespace std;

// This needs O(n) extra space and is an example of a not-in-place algorithm.
void reverseArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> revArr(n);

    for (int i = 0; i < n; i++)
    {
        // cout<<revArr[i]<<endl;
        revArr[i] = arr[n - i - 1];
    }

    for (int j = 0; j < n; j++)
    {
        arr[j] = revArr[j];
    }
}

void revArrInPlace(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n / 2; i++)
    {

        cout << arr[n / 2] << endl;
        swap(arr[i], arr[n - i - 1]);
    }
}

/* Utility function to print an array */
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 11, 3, 4, 2, 6, 7, 8, 9};
    // reverseArray(arr);
    revArrInPlace(arr);
    printArray(arr);
    return 0;
}