#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//  function to sorts a nearly sorted array
// where every element is at most
// k positions away from its target position.
void nearlySorted(vector<int> &arr, int k)
{
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    int i;
    for (i = k; i < n; i++)
    {
        pq.push(arr[i]);
        // Size become k+1 so pop it and minium element is (k-1) index;
        arr[i - k] = pq.top();
        pq.pop();
    }

    // puting remaining elements in array
    while (!pq.empty())
    {
        arr[i - k] = pq.top();
        pq.pop();
        i++;
    }
}

int main()
{
    vector<int> arr = {6, 12, 5, 3, 2, 8, 10, 9};
    int k = 3;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';
    return 0;
}