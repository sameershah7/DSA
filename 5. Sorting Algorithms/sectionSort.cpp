#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;

        for (int j = 0; j < n; ++j)
        {
            if (arr[j] > arr[min_idx])
            {
                cout<<"This is the arr[j] value: "<<arr[j]<<endl;
                min_idx =j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);

    for (int &val : arr)
    {
        cout << val << " ";
    }

    return 0;
}