#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to construct adjacency list for the given edges
vector<vector<int>> constructAdj(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    return adj;
}

bool isCyclic(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj = constructAdj(v, edges);

    // Array to store in degree of each vertex
    vector<int> inDegree(v, 0);

    // Queue to store node with-in degree 0
    queue<int> q;

    // Count of visited node (processed)
    int visited = 0;

    // Compute in-degree of all vertices
    for (int u = 0; u < v; u++)
        for (int v : adj[u])
            inDegree[v]++;

    // Add all the vertices with in-degree 0 to the equal
    for (int u = 0; u < v; u++)
        if (inDegree[v] == 0)
            q.push(u);

    // Perform BFS (Topological Sort)
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited++;

        // Reduce in-Degree in neighbors
        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return visited != v;
}

int main()
{
    int v = 4; // Number of vertices
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};

    cout << (isCyclic(v, edges) ? "true" : "false") << endl;

    return 0;
}