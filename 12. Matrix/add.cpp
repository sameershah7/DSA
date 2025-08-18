#include <bits/stdc++.h>

using namespace std;

void add(vector<vector<int>> &A, vector<vector<int>> &B,
         vector<vector<int>> &C)
{
    int n = A.size();
    int m = A[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
int main()
{
    vector<vector<int>> A = {{1, 1, 1},
                             {2, 2, 2},
                             {3, 3, 3},
                             {4, 4, 4}};

    vector<vector<int>> B = {{1, 1, 1},
                             {2, 2, 2},
                             {3, 3, 3},
                             {4, 4, 4}};
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>> C(n, vector<int>(m));

    add(A, B, C);
    cout << "Result matrix is:" << endl;
    for (const auto &row : C)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}