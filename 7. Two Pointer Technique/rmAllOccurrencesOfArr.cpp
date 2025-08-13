#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &arr, int ele)
{
    int k = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != ele)
        {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}

int main()
{
    vector<int> arr = {0, 9, 3, 4, 5, 6, 7, 2, 2, 4, 2};
    int ele = 2;
    cout << removeElement(arr, ele) << endl;
    return 0;
}