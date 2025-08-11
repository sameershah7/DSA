#include <bits/stdc++.h>
using namespace std;

int isSubset(vector<int> &a, vector<int> &b)
{

    // // [Naive approach] Using Nested Loops - O(m*n) Time and O(1) Space
    // int m = a.size(), n = b.size();
    // for (int i = 0; i < n; i++)
    // {
    //     bool found = false;
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (b[i] == a[j])
    //         {
    //             found = true;
    //             break;
    //         }
    //     }
    //     if (!found)
    //         return false;
    // };
    // return true;


    // [Expected Approach] Using Hashing- O(m + n) Time and O(m) Space
    // Creat hash set and insert all elements of a
    unordered_set<int> hashSet(a.begin(), a.end());

    // check each element of b and the hash set
    for (int num : b)
    {
        if (hashSet.find(num) == hashSet.end())
        {
            return false;
        }
    }

    //if the all element of b in found in hastSet then return true
    return true;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 2, 6, 7, 8};
    vector<int> b = {1, 2, 3, 1, 3, 1};

    if (isSubset(a, b))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}