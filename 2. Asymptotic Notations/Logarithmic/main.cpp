// Logarithmic time complexity means that the running time of an algorithm is proportional to the logarithm of the input size. used when the data is sorted

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2; // middle 8, key = 23

        // Check if key is at mid
        if (arr[mid] == key)
            return mid;

        // If key is greater, ignore left half
        if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    // Key not found
    return -1;
}

int binarySearchRecursive(vector<int> &arr, int left, int right, int target) {
    if (left > right) return -1;  // base case: not found

    int mid = (left + right) / 2;

    // base case: found the element
    if (arr[mid] == target) {
        return mid;
    }

    // search left half
    if (arr[mid] > target) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }

    // search right half
    return binarySearchRecursive(arr, mid + 1, right, target);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int key = 6;
    // int result = binarySearch(arr, key);
    int result = binarySearchRecursive(arr, 0, arr.size() - 1, key);

    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}