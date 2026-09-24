#include <iostream>
#include <vector>

using namespace std;

// Recursive helper function for DFS
void dfsHelper(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    // 1. Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // 2. Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

// Main function to handle DFS traversal
void dfs(int startNode, const vector<vector<int>>& adj, int totalVertices) {
    // Create a visited array initialized to false
    vector<bool> visited(totalVertices, false);

    // Call the recursive helper function
    dfsHelper(startNode, adj, visited);
}

int main() {
    int vertices = 5;
    
    // Graph represented as an adjacency list
    vector<vector<int>> adj(vertices);

    // Add edges (Undirected Graph Example)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    cout << "Depth First Traversal starting from node 0:\n";
    dfs(0, adj, vertices);

    return 0;
}
