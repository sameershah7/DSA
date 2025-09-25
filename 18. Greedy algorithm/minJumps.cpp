#include <iostream>
#include <vector>
using namespace std;

int minJumps(vector<int> &arr)
{
    int n = arr.size();

    if (arr[0] == 0)
        return -1;

    int maxReach = 0;
    int currReach = 0;
    int jump = 0;

    for (int i = 0; i < n; i++)
    {
        maxReach = max(maxReach, i + arr[i]);
        if (maxReach >= n - 1)
            return jump + 1;

        // Increment the jump as we reach
        // the current reachable index
        if (i == currReach)
        {
            // if max reach is same as current index
            // then we can't jumps further
            if (maxReach == i)
                return -1;

            // if maxReach > current index then increment and
            // jump update the current reachable index
            else
            {
                jump++;
                currReach = maxReach;
            }
        }
    }
    return -1;
}

int main()
{
vector<int> arr = {1, 3, 2, 2, 1, 4, 6};
    cout << minJumps(arr);
    return 0;
}