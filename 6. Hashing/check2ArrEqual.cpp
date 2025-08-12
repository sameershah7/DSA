#include <bits/stdc++.h>

using namespace std;

bool checkEqual(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    if (n != m)
        return false;

    // [Naive Approach] Using Sorting - O(n*log n) Time and O(1) Space
    //
    //     sort(a.begin(), a.end());
    //     sort(b.begin(), b.end());
    //
    //     for (int i = 0; i < n ; i++)
    //     {
    //         if ( a[i] != b[i]){
    //             return false;
    //         }
    //     }
    //     return true;

    // [Expected Approach] Using Hashing- O(n) Time and O(n) Space
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) == mp.end())
            return false;

        if (mp[b[i]] == 0)
            return false;

        mp[b[i]]--;
    }

    return true;
}

int main()
{
    vector<int> a = {3, 5, 2, 5, 2};
    vector<int> b = {2, 3, 5, 5, 2};

    if (checkEqual(a, b))
        cout << "true";
    else
        cout << "false";
    return 0;
}