#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int isValid(vector<vector<int>> &mat)
{

    // Track of numbers in rows, columns, and sub-matrix
    unordered_set<int> rows[9];
    unordered_set<int> cols[9];
    unordered_set<int> subMat[9];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            // Get the value at the current cell
            int val = mat[i][j];

            // For empty(0), Skip to the next cell
            if (val == 0)
                continue;

            // Check if the value already exists int the current row
            if (rows[i].find(val) != rows[i].end())
                return false;

            // Insert the value into the current row's set
            rows[i].insert(val);

            // Check if the value is already exists in the current column
            if (cols[j].find(val) != cols[j].end())
                return false;

            // Insert the value into the current column's set
            cols[j].insert(val);

            // Calculate the index for the 3x3 box
            int idx = (i / 3) * 3+ j / 3;

            // Check if the value already exists in the current 3x3 box
            if(subMat[idx].find(val) != subMat[idx].end())
                return false;

            // Insert the value into the current box's set
            subMat[idx].insert(val);
        }

    return true;
}

int main()
{
    vector<vector<int>> mat = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << (isValid(mat) ? "true" : "false") << "\n";

    return 0;
}