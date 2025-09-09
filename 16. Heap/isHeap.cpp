#include <iostream>
using namespace std;

bool isHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        // Check if the current node is greater than its left child
        if (arr[i] < arr[2 * i + 1])
        {
            return false;
        }
        // Check if the right child exists and is greater than the current node
        if (2 * i + 2 < n && arr[i] < arr[2 * i + 2])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int) - 1;

    isHeap(arr, n) ? printf("Yes") : printf("No");

    return 0;
}