#include <bits/stdc++.h>
using namespace std;

void pushZerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);

    // To keep trace of the index
    int j = 0;

    // Copy non zero element temp
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp[j++] = arr[i];
        }
    }


    // fill the remain position with 0
    while (j < n)
    {
        temp[j++] = 0;
    }

    // Copy all the elements from temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);

    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}
