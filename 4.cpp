#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <functional> // Include for 'function'
using namespace std;

// Structure to represent a node in the graph
struct Node {
    int index; // Index of the node
    int g_cost; // Cost from start node to this node
    int h_cost; // Heuristic cost (estimated cost from this node to goal node)
    int f_cost; // f(n) = g(n) + h(n)
    int parent; // Parent node index
    Node(int i, int g, int h, int p) : index(i), g_cost(g), h_cost(h), f_cost(g + h), parent(p) {}
};

// A* algorithm function
int AStar(vector<vector<int>>& graph, vector<int>& heuristic, int start, int goal, vector<int>& path) {
    int n = graph.size();

    // Priority queue to store nodes to be explored, ordered by f_cost
    priority_queue<Node, vector<Node>, function<bool(const Node&, const Node&)>> openList(
        [](const Node& a, const Node& b) {
            return a.f_cost > b.f_cost;
        }
    );

    // Vector to keep track of visited nodes and their parent
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    // Add the start node to the open list
    openList.push(Node(start, 0, heuristic[start], -1));

    while (!openList.empty()) {
        // Get the node with the lowest f_cost from the open list
        Node current = openList.top();
        openList.pop();

        // Check if the current node is the goal
        if (current.index == goal) {
            // Construct the shortest path
            int node = current.index;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end()); // Reverse the path to get it from start to goal
            return current.g_cost;
        }

        // Mark current node as visited
        visited[current.index] = true;

        // Expand current node
        for (int neighbor = 0; neighbor < n; ++neighbor) {
            // Check if there is a connection from current node to neighbor and neighbor is not visited
            if (graph[current.index][neighbor] != 0 && !visited[neighbor]) {
                int g_cost = current.g_cost + graph[current.index][neighbor];
                int h_cost = heuristic[neighbor];
                int f_cost = g_cost + h_cost;

                // Add neighbor to open list
                openList.push(Node(neighbor, g_cost, h_cost, current.index));

                // Update parent information
                parent[neighbor] = current.index;
            }
        }
    }

    // If goal node is not reachable
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> heuristic(n, 0);

    cout << "Enter the heuristic values for each node:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> heuristic[i];
    }

    int start, goal;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> goal;

    vector<int> path;
    int shortestPathCost = AStar(graph, heuristic, start, goal, path);

    if (shortestPathCost == -1) {
        cout << "No path found from node " << start << " to node " << goal << endl;
    } else {
        cout << "Shortest path cost from node " << start << " to node " << goal << " is: " << shortestPathCost << endl;
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <functional> // Include for 'function'
using namespace std;

// Structure to represent a node in the graph
struct Node {
    int index; // Index of the node
    int g_cost; // Cost from start node to this node
    int h_cost; // Heuristic cost (estimated cost from this node to goal node)
    int f_cost; // f(n) = g(n) + h(n)
    int parent; // Parent node index
    Node(int i, int g, int h, int p) : index(i), g_cost(g), h_cost(h), f_cost(g + h), parent(p) {}
};

// A* algorithm function
int AStar(vector<vector<int>>& graph, vector<int>& heuristic, int start, int goal, vector<int>& path) {
    int n = graph.size();

    // Priority queue to store nodes to be explored, ordered by f_cost
    priority_queue<Node, vector<Node>, function<bool(const Node&, const Node&)>> openList(
        [](const Node& a, const Node& b) {
            return a.f_cost > b.f_cost;
        }
    );

    // Vector to keep track of visited nodes and their parent
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    // Add the start node to the open list
    openList.push(Node(start, 0, heuristic[start], -1));

    while (!openList.empty()) {
        // Get the node with the lowest f_cost from the open list
        Node current = openList.top();
        openList.pop();

        // Check if the current node is the goal
        if (current.index == goal) {
            // Construct the shortest path
            int node = current.index;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end()); // Reverse the path to get it from start to goal
            return current.g_cost;
        }

        // Mark current node as visited
        visited[current.index] = true;

        // Expand current node
        for (int neighbor = 0; neighbor < n; ++neighbor) {
            // Check if there is a connection from current node to neighbor and neighbor is not visited
            if (graph[current.index][neighbor] != 0 && !visited[neighbor]) {
                int g_cost = current.g_cost + graph[current.index][neighbor];
                int h_cost = heuristic[neighbor];
                int f_cost = g_cost + h_cost;

                // Add neighbor to open list
                openList.push(Node(neighbor, g_cost, h_cost, current.index));

                // Update parent information
                parent[neighbor] = current.index;
            }
        }
    }

    // If goal node is not reachable
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> heuristic(n, 0);

    cout << "Enter the heuristic values for each node:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> heuristic[i];
    }

    int start, goal;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> goal;

    vector<int> path;
    int shortestPathCost = AStar(graph, heuristic, start, goal, path);

    if (shortestPathCost == -1) {
        cout << "No path found from node " << start << " to node " << goal << endl;
    } else {
        cout << "Shortest path cost from node " << start << " to node " << goal << " is: " << shortestPathCost << endl;
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
