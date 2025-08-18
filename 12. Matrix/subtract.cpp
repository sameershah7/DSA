#include <bits/stdc++.h>

using namespace std;

void subtract(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &res)
{
    int rows = A.size();
    int cols = A[0].size();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res[i][j] = A[i][j] - B[i][j];
}

int main()
{
    vector<vector<int>> m1 = {{2, 2, 2},
                              {3, 3, 3},
                              {4, 4, 4}};

    vector<vector<int>> m2 = {{2, 2, 2},
                              {4, 4, 4},
                              {3, 3, 3}};

    int n = m1.size();
    int m = m1[0].size();
    vector<vector<int>> res(n, vector<int>(m));

    subtract(m1, m2, res);

    // Print the result matrix
    cout << "Result matrix is:" << endl;
    for (auto &row : res)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
// Time complexity: O(n^2)