#include <iostream>
#include <vector>

using namespace std;

int equilibriumPoint(vector<int> &arr)
{
    int prefSum = 0, total = 0;

    // Calculate the array sum
    for (int ele : arr)
    {
        total += ele;
    }

    // Iterate pivot over all the elements of the array and
    // till left != right

    for (int i = 0; i < arr.size(); i++)
    {
        int suffSum = total - prefSum - arr[i];
        if (prefSum == suffSum)
            return i;
        

        prefSum += arr[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 7, 3, 6, 5, 6};

    cout << equilibriumPoint(arr) << endl;
    return 0;
}