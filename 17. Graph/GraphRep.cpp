#include <bits/stdc++.h>
using namespace std;

// C++ program to demonstrate Adjacency Matrix
// representation of undirected and unweighted graph
void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void displayMatrix(vector<vector<int>> &mat)
{
    int s = mat.size();
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int v = 4;
    vector<vector<int>> mat(v, vector<int>(v, 0));
    /* Alternatively we can also create using below
      code if we know all edges in advacem

    vector<vector<int>> mat = {{ 0, 1, 0, 0 },
                              { 1, 0, 1, 0 },
                              { 0, 1, 0, 1 },
                              { 0, 0, 1, 0 } }; */

    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;
}