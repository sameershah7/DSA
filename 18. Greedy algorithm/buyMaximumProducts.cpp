#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> v;
    // Making pair of product cost and number of days
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(price[i], i + 1));

    // sort the vector pair
    sort(v.begin(), v.end());

    // Calculating the maximum number of stock count
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second, (k / v[i].first));
    }
    return ans;
}

int main()
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << endl;

    return 0;
}