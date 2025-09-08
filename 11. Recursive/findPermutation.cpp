#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all permutations of string s
void recurPermute(int index, string &s, vector<string> &ans)
{
    if (index == s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        recurPermute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

// Function to find all the unique permutation
vector<string> findPermutation(string &s)
{
    vector<string> ans;
    int idx = 0;
    recurPermute(idx, s, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "ABC";
    vector<string> res = findPermutation(s);
    for (auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}