// Matrix Data Structure
// Matrix Data Structure is a two-dimensional array arranged in rows and columns. It is commonly used to represent mathematical matrices and is fundamental in various fields like mathematics, computer graphics, and data processing. Matrices allow for efficient storage and manipulation of data in a structured format.

#include <bits/stdc++.h>
using namespace std;

bool matrixSearch(vector<vector<int>> &mat, int x)
{
    int n = mat.size(), m = mat[0].size();

    // compare each element one by one
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == x)
                return true;
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1, 5, 9, 11},
                               {14, 20, 21, 26},
                               {30, 34, 43, 50}};
    int search = 20;
    if (matrixSearch(mat, search))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}