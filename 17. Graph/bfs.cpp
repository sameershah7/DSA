#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj)
{
    int V = adj.size();
    int s = 0; // Source node

    // Create an array to store traversal
    vector<int> res;

    // Create a queue for BFS
    queue<int> q;

    // Initially marks all the vertices as not visited
    vector<bool> visited(V, false);

    // Marks node is visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        // Dequeue a vertex from queue and store it
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeue
        // vertex is curr if and adjacent has not been
        // visited, mark it visited and enqueue it

        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    vector<int> ans = bfs(adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}