#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Helper function to perform BFS from a specific source node
void bfsComponent(int startNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    
    // Mark the starting node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);
    
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        
        // Traverse all neighbors of the current node
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Main BFS function that handles disconnected graphs
void completeBfs(const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false);
    
    cout << "BFS Traversal: ";
    // Loop through all nodes to ensure disconnected components are visited
    for (int i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            bfsComponent(i, adjList, visited);
        }
    }
    cout << endl;
}

// Function to add an undirected edge
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); 
}

int main() {
    // Total 6 nodes (0 to 5)
    int totalNodes = 6; 
    vector<vector<int>> adjList(totalNodes);
    
    // Component 1
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    
    // Component 2 (Disconnected from Component 1)
    addEdge(adjList, 3, 4);
    addEdge(adjList, 4, 5);
    
    // Execute BFS over the entire graph
    completeBfs(adjList);
    
    return 0;
}

