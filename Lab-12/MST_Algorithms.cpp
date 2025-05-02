//Menu Driven Program to implement Graph ADT with implementation for Prim's algorithm, Kruskal's algorithm and Dijkstra's algorithm
#include <cstdio>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, weight;
};

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int w) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            printf("Invalid vertices.\n");
            return;
        }
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w); 
    }
//Function for Prim's Algorithm
    void primMST() {
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;

        for (int i = 0; i < V - 1; ++i) {
            int u = -1;
            for (int j = 0; j < V; ++j)
                if (!inMST[j] && (u == -1 || key[j] < key[u]))
                    u = j;

            inMST[u] = true;

            for (auto [v, w] : adjList[u]) {
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        printf("Prim's MST:\n");
        for (int i = 1; i < V; ++i)
            printf("%d - %d\n", parent[i], i);
    }

    int findSet(int u, vector<int>& parent) {
        if (parent[u] != u)
            parent[u] = findSet(parent[u], parent);
        return parent[u];
    }

    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findSet(u, parent);
        v = findSet(v, parent);
        if (u != v) {
            if (rank[u] < rank[v])
                swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v])
                ++rank[u];
        }
    }
//Function for Kruskal's Algorithm
    void kruskalMST() {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; ++i) parent[i] = i;

        printf("Kruskal's MST:\n");
        for (Edge e : edges) {
            if (findSet(e.u, parent) != findSet(e.v, parent)) {
                printf("%d - %d\n", e.u, e.v);
                unionSets(e.u, e.v, parent, rank);
            }
        }
    }
//Function for Dijkstra's Algorithm 
    void dijkstra(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, src);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            for (auto [v, w] : adjList[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        printf("Dijkstra's shortest paths from node %d:\n", src);
        for (int i = 0; i < V; ++i)
            printf("To %d -> %d\n", i, dist[i]);
    }
};

int main() {
    int V, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    Graph g(V);

    while (true) {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Prim's MST\n");
        printf("3. Kruskal's MST\n");
        printf("4. Dijkstra's Algorithm\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int u, v, w;
            printf("Enter edge (u v w): ");
            scanf("%d %d %d", &u, &v, &w);
            g.addEdge(u, v, w);
        }
        else if (choice == 2) {
            g.primMST();
        }
        else if (choice == 3) {
            g.kruskalMST();
        }
        else if (choice == 4) {
            int src;
            printf("Enter source vertex: ");
            scanf("%d", &src);
            g.dijkstra(src);
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
