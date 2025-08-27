#include <bits/stdc++.h>

using namespace std;

void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();
    for (int i = 0; i < d; i++)
    {
        int last = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int d = 3;
    // This output will be 4 5 6 1 2 3

    rotateArr(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}