#include <bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // 2D vector to store the frequency of each elements
    vector<vector<int>> freq;

    // Sorting frequency in descending order
    auto comp = [&](vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > a[0];
    };
    
    for (int i = 0; i < n; i++)
    {

        // to store the frequency
        int cnt = 1;
        while (i < n - 1 && arr[i] == arr[i + 1])
        {
            cnt++;
            i++;
        }

        // push the frequency and the element
        freq.push_back({cnt, arr[i]});
    }

    // sort the frequency array
    sort(freq.begin(), freq.end(), comp);

    // to store the answer
    vector<int> ans;

    // push the elements in the answer array
    for (int i = 0; i < freq.size(); i++)
    {
        for (int j = 0; j < freq[i][0]; j++)
        {
            ans.push_back(freq[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {5, 5, 4, 6, 4};
    vector<int> ans = sortByFreq(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}