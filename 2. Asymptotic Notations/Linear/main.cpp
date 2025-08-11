// What Does O(n) Mean?
// Big O(n) means that the time taken grows linearly with the size of the input.
// If the input doubles, the time it takes to run the code also (approximately) doubles.

#include <iostream>
#include <vector>
using namespace std;

bool findValue(int arr[], int size, int fValue)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == fValue)
        {
            return arr[i];
        }
    }
    return -1;
}

int search(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // printing array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Finding max in an array
    int max_value = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    cout << "\n The mix number in array: " << max_value;

    // This function work is finding the give value
    cout << "\n The is available: "
         << findValue(arr, n, 5);

    // search function
    // vector:  It provides a sequence container that can store elements of the same data type in a contiguous block of memory and dynamically grow or shrink in size as elements are added or removed during program execution.

    vector<int> searchArr = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << "\n"
         << search(searchArr, 3);

    return 0;
}

//  Time Complexity: O(n)
// Because we loop through the array once.
// For each element, we do one constant-time operation: printing it.
// So for n elements → it runs in O(n) time.