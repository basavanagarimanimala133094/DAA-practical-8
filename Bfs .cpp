#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth First Search on a graph
void bfs(int startNode, const vector<vector<int>>& adjList) {
    // Vector to keep track of visited vertices, initialized to false
    vector<bool> visited(adjList.size(), false);
    
    // Queue data structure needed for BFS traversal
    queue<int> q;
    
    // Mark the starting node as visited and push it into the queue
    visited[startNode] = true;
    q.push(startNode);
    
    cout << "BFS Traversal: ";
    
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        
        // Get all adjacent vertices of the dequeued vertex.
        // If an adjacent vertex has not been visited, mark it visited and enqueue it.
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// Function to add an undirected edge to the adjacency list
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Remove this line if working with a Directed Graph
}

int main() {
    int totalNodes = 5;
    vector<vector<int>> adjList(totalNodes);
    
    // Constructing an example graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    
    // Run BFS starting from node 0
    bfs(0, adjList);
    
    return 0;
}
