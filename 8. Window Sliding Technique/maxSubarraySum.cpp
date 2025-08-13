#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> &arr, int k)
{
    int n = arr.size();
    queue<int> q;
    int sum = 0, maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        q.push(arr[i]);

        // maintain window of size k
        if (q.size() > k)
        {
            sum -= q.front();
            q.pop();
        }

        // update maximum when window size becomes k
        if (q.size() == k)
        {
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << maxSubarraySum(arr, k) << endl;
    return 0;
}