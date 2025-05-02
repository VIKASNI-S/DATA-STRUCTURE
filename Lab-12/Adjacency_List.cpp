//C++ menu-driven program to implement Graph ADT with an adjacency list
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Graph {
private:
    int V;  
    vector<list<int>> adjList; 

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Insert an edge from u to v
    void insertEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex. Please enter a vertex between 0 and " << V-1 << endl;
            return;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
        cout << "Edge inserted between " << u << " and " << v << endl;
    }

    // Delete an edge from u to v
    void deleteEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex. Please enter a vertex between 0 and " << V-1 << endl;
            return;
        }

        adjList[u].remove(v);
        adjList[v].remove(u);  
        cout << "Edge deleted between " << u << " and " << v << endl;
    }

    // Search for an edge between u and v
    void searchEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex. Please enter a vertex between 0 and " << V-1 << endl;
            return;
        }

        if (find(adjList[u].begin(), adjList[u].end(), v) != adjList[u].end()) {
            cout << "Edge found between " << u << " and " << v << endl;
        } else {
            cout << "No edge exists between " << u << " and " << v << endl;
        }
    }

    // Display the adjacency list of the graph
    void displayGraph() {
        cout << "\nAdjacency List Representation of the Graph:\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            for (auto neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Menu-driven program for operations
    void menu() {
        int choice, u, v;
        while (true) {
            cout << "\nMenu:\n";
            cout << "1. Insert an edge\n";
            cout << "2. Delete an edge\n";
            cout << "3. Search an edge\n";
            cout << "4. Display the graph\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the vertices (u, v) to insert an edge: ";
                    cin >> u >> v;
                    insertEdge(u, v);
                    break;
                case 2:
                    cout << "Enter the vertices (u, v) to delete an edge: ";
                    cin >> u >> v;
                    deleteEdge(u, v);
                    break;
                case 3:
                    cout << "Enter the vertices (u, v) to search an edge: ";
                    cin >> u >> v;
                    searchEdge(u, v);
                    break;
                case 4:
                    displayGraph();
                    break;
                case 5:
                    cout << "Exiting the program.\n";
                    return;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        }
    }
};

int main() {
    int vertices;
    cout << "Enter number of vertices in the graph: ";
    cin >> vertices;

    Graph g(vertices);
    g.menu();  
    return 0;
}
