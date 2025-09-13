#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS for given source
void bfs(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<int> &res)
{
    // Create queue for FBS
    queue<int> q;

    // Mark source node as visited and inqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty())
    {
        // Dequeue are vertex and store
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeue vertex curr 
        // If adjacent are not been visited visited marks.
        // Mark it visited and enqueue it
        for(auto x: adj[curr]){
            if(!visited[curr]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// Perform BFS for the entire graph which maybe disconnect
vector<int> bfsDisconnected(vector<vector<int>> &adj)
{
    int V = adj.size();

    // create any array to store traversal
    vector<int> res;

    // Initially marks all the vertices are not visited
    vector<bool> visited(V, false);

    // Perform bfs for each node
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bfs(adj, i, visited, res);
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> adj = {{1, 2}, {0}, {0}, {4}, {3, 5}, {4}};
    vector<int> ans = bfsDisconnected(adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}