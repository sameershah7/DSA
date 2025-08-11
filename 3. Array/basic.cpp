#include <bits/stdc++.h>
using namespace std;

bool searchInMatrix(vector<vector<int>> &arr, int x)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == x){
                return true;
            }
        }
    }

    return false;
}

int main()
{

    // Initializing a 1-D vector with values
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    // Initializing a 2-D vector with values
    vector<vector<int>> arr2D = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12}};

    // Traversing over all the rows
    for (int i = 0; i < arr2D.size(); i++)
    {

        // Traversing over all the columns of each row
        for (int j = 0; j < arr2D[i].size(); j++)
        {
            // cout << arr2D[i][j] << " ";
        }
        // cout << endl;
    }

    // checking function
    // cout << searchInMatrix(arr, 172) << endl;

    // Reverse Traversal
    for (int i = arr.size()-1; i >= 0; i--)
    {
        cout<< i<<endl;
    }
    
  
    
    return 0;
}