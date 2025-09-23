#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate minimum price
int cost(vector<int> &a)
{
    // Minimum cost is (size -1) multiple with the minimum element
    int n = a.size();
    return (n - 1) * (*min_element(a.begin(), a.end()));
}

int main()
{
    vector<int> a = {4, 3, 2};
    vector<int> b = {4, 2};
    cout << cost(a) << endl;
    cout << cost(b) << endl;
    return 0;
}