#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, int>> v;

void solve(int n, int d, int a, int b, int arr[][2])
{
    for (int i = 0; i < n; i++)
    {
        int m = arr[i][0], t = arr[i][1];
        v.push_back(make_pair((a * m + b * t), i + 1));
    }

    sort(v.begin(), v.end());

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (v[i].first <= d)
        {
            ans.push_back(v[i].second);
            d -= v[i].first;
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    int n = 5;
    long d = 5;
    int a = 1, b = 1;
    int arr[][2] = {{2, 0},
                    {3, 2},
                    {4, 4},
                    {10, 0},
                    {0, 1}};

    solve(n, d, a, b, arr);
    return 0;
}