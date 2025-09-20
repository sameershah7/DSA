#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

// Recursive DFS to explore all paths from current position
void dfs(int currPos, int movesMade, vector<int> &move, unordered_map<int, int> &visited, int n, int &res)
{
    // Prune paths that are worse then already found are visited;
    if (movesMade >= res || (visited.count(currPos) && movesMade >= visited[currPos]))
        return;

    // Reached the last cell and update the result
    if (currPos == n - 1)
    {
        res = movesMade;
        return;
    }
    visited[currPos] = movesMade;

    // Explore the dice throw (1 to 6)
    for (int i = 1; i <= 6 && currPos + i < n; ++i)
    {
        int nextPos = currPos + i;

        // Jump if ladder/snake present
        int dest = (move[nextPos] != -1) ? move[nextPos] : nextPos;

        dfs(dest, movesMade + 1, move, visited, n, res);
    }
}

// Function to find the minimum number of dice throws
int getMinDicThrows(vector<int> &move)
{
    int n = move.size();
    unordered_map<int, int> visited;
    int res = INT_MAX;
    // Start DFS from cell 0
    dfs(0, 0, move, visited, n, res);
    return (res == INT_MAX) ? -1 : res;
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