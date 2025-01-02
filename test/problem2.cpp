/*
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
class Node {
    public int val;
    public List<Node> neighbors;
}
Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Write your code here
    }
};

// Helper function to print the graph (for testing)
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node || visited[node]) return;
    visited[node] = true;
    cout << "Node " << node->val << ": ";
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;
    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

// Helper function to create a graph from adjacency list
Node* createGraph(const vector<vector<int>>& adjList) {
    if (adjList.empty()) return nullptr;

    vector<Node*> nodes(adjList.size());
    for (int i = 0; i < adjList.size(); ++i) {
        nodes[i] = new Node(i + 1);
    }
    for (int i = 0; i < adjList.size(); ++i) {
        for (int neighbor : adjList[i]) {
            nodes[i]->neighbors.push_back(nodes[neighbor - 1]);
        }
    }
    return nodes[0];
}

// Driver Code
int main() {
    Solution solution;

    // Test case: [[2,4],[1,3],[2,4],[1,3]]
    vector<vector<int>> adjList = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    Node* graph = createGraph(adjList);

    // Clone the graph
    Node* clonedGraph = solution.cloneGraph(graph);

    // Print the cloned graph
    unordered_map<Node*, bool> visited;
    printGraph(clonedGraph, visited);

    return 0;
}
