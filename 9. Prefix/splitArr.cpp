// Time Complexity : O(n) , Auxiliary Space : O(1)

#include <iostream>
using namespace std;

int findSplitPoint(int arr[], int n)
{
    // travel element and compute sum of hole array
    int leftSum = 0;
    for (int i = 0; i < n; i++)
        leftSum += arr[i];

    // again travel the array and complete right sum
    // also check leftSum equal to write
    // sum or not
    int rightSum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // add current element to right_sum
        rightSum += arr[i];

        // exclude current element to the left_sum
        leftSum -= arr[i];

        if (rightSum == leftSum)
            return i;
    }
    return -1;
}

void printTwoParts(int arr[], int n)
{
    int splitPoint = findSplitPoint(arr, n);

    if (splitPoint == -1 || splitPoint == n)
    {
        cout << "Not Possible: " << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (splitPoint == i)
            cout << endl;
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoParts(arr, n);
    return 0;
}