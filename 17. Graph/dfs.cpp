#include <iostream>
#include <vector>
using namespace std;

// Recursive function for DFS traversal
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{
    visited[s] = true;
    res.push_back(s);
    // Recursively visit all adjacent vertices that are not visited
    for (int i : adj[s])
    {
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
    }
}

// Main DFS that initialize the visited array and call DFSres
vector<int> DFS(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    // Don't need to through all vertices for connected graph
    // dfsRec(adj, visited, 0, res);

    // Loop through all vertices to handle disconnected graph
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i] == false)
        {
            // If vertex i has not been visited, perform DFS from it
            dfsRec(adj, visited, i, res);
        }
    }
    return res;
}

// To add edge to undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    // Add edges
    // Connected edges
    // vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

    // Disconnected edges
    vector<vector<int>> edges = {{0, 1}, {2, 3}, {3, 4}};

    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    // Perform DFS starting from the source vertex 0;
    vector<int> res = DFS(adj);

    for (auto i : res)
        cout << i << " ";

    return 0;
}