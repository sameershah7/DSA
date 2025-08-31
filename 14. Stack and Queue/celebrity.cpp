#include <iostream>
#include <vector>

using namespace std;

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        // j know i, thus j can't be celebrity
        if (mat[j][i] == 1)
        {
            j--;
        }
        else
        {
            // else i can't be celebrity
            i++;
        }
    }
    // i pointer to our celebrity candidate
    int c = i;

    for (int i = 0; i < n; i++)
    {
        // check if the c is actual celebrity or not
        if (i == c)
            continue;

        // know 'c' or 'c' doesn't know any person, return -1
        if (mat[c][i] || !mat[i][c])
            return -1;
    }
    return c;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0},
                               {0, 1, 0},
                               {0, 1, 1}};
    cout << celebrity(mat);
    return 0;
}