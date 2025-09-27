#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int minPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {arr[i], dep[i]};

    // Sort by arrival time
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top() < v[i].first)
            pq.pop();

        // add current train's departure
        pq.push(v[i].second);

        // trace minimum platform used
        ans = max(ans, (int)pq.size());
    }
    return ans;
}
int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatform(arr, dep);
    return 0;
}