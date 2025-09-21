#include <bits/stdc++.h>
using namespace std;

// Constructs an adjacency list for a directed graph
vector<vector<int>> constructadj(int V, const vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (const auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    return adj;
}

// Utility function for DFS traversal and cycle detection
// Uses coloring method to detect back edges
bool dfsutil(int u, vector<vector<int>> & adj,vector<int> &color){
    int gray = 1, black =  2;

    // Mark the current node as being processed(gray)
    color[u] = gray;

    // Visit all the neighbors
    for (int v: adj[u])
    {
        // if the neighbor is also gray, we found a black edge cycle
        if(color[v] == gray)
            return true;

        // if the neighbor is unvisited (white), recur on it
        if(color[v] ==  0 && dfsutil(v, adj, color))
            return true;
    }

    // After processing all neighbors, mark the node is finished (black)
    color[u] = black;
    return false;   

}

// Main function to detect cycle in a direct graph
bool isCyclic(int v, vector<vector<int>> & edges){
    // Define color values locally:
    // 0 - white (unvisited), 1 - gray (visiting) 2 - black (visited)
    vector<int> color(v, 0);

    // Build the adjacency list from edges list
    vector<vector<int>> adj = constructadj(v, edges);

    // Perform DFS from every unvisted node
    for (int i = 0; i < v; i++)
        if(color[i] == 0)
            if(dfsutil(i, adj, color))
                return true;

    return false;
}

int main()
{
    // int V = 4;
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}, {3, 3}};
    int V = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}};

    cout << (isCyclic(V, edges) ? "true" : "false") << endl;

    return 0;
}