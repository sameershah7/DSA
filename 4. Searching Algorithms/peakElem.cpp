#include <iostream>
#include <vector>
using namespace std;

// This will be worked with sort array as argument
int peakElement(vector<int> &arr)
{
    int n = arr.size();

    // If there is only one element, then it's a peak
    if (n == 1)
        return 0;

    // Check if the first element is a peak
    if (arr[0] > arr[1])
        return 0;

    // Check if the last element is a peak
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    // Search Space for binary Search
    int lo = 1, hi = n - 2;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        // If the element at mid is a peak element return  mid
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        // If next neighbor is greater, then peak element will exist in the right subarray
        if (arr[mid] < arr[mid + 1])
            lo = mid + 1;

        // Otherwise, it will exist in left subarray
        else
            hi = mid - 1;
    }

    return 0;
}

// Function that search binary if element is found return his index
//  Not found the return -1
int binarySearch(vector<int> &arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (key == arr[mid])
        {
            return mid;
        }

        if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 10, 7, 8, 3};
    cout << "index: " << peakElement(arr)<<endl;
    cout<< binarySearch(arr, 8);
    return 0;
}