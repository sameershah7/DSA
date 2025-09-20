#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the minimum number of dic throws BFS
int getMinDiceThrowsBFS(vector<int> &move)
{
    int n = move.size();
    vector<bool> visited(n, false);
    queue<vector<int>> q;

    visited[0] = true;
    q.push({0, 0});

    while (!q.empty())
    {
        vector<int> curr = q.front();
        int v = curr[0];
        int dist = curr[1];

        if (v == n - 1)
            return dist;

        q.pop();

        // Try all the possible throw from the current cell
        for (int j = v + 1; j <= v + 6 && j < n; ++j)
        {
            if (!visited[j])
                visited[j] = true;

            // Move to destination cell if there is ladder/snake
            int dest = (move[j] != -1) ? move[j] : j;
            q.push({dest, dist + 1});
        }
    }
    return -1;
}


int main()
{
    int n = 30;
    vector<int> moves(n, -1);

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << getMinDiceThrowsBFS(moves);
    return 0;
}