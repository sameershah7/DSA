#include <iostream>
#include <vector>
using namespace std;

double findMean(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return (double)arr[n - 1];

    else
        return ((double)(findMean(vector<int>(arr.begin(), arr.begin() + n - 1)) * (n - 1) + arr[n - 1]) / n);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << findMean(arr) << endl;
    return 0;
}