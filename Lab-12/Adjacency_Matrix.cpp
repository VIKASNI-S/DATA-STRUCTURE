#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10  // Maximum number of nodes in the graph

// Function to initialize the adjacency matrix
void initializeMatrix(int matrix[MAX_NODES][MAX_NODES], int nodes) {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            matrix[i][j] = 0;  // Initialize all values to 0
        }
    }
}

// Function to add an edge to the graph (undirected graph)
void addEdge(int matrix[MAX_NODES][MAX_NODES], int start, int end) {
    matrix[start][end] = 1;  // Add edge from start to end
    matrix[end][start] = 1;  // Since undirected, add the reverse edge as well
}

// Function to print the adjacency matrix
void printMatrix(int matrix[MAX_NODES][MAX_NODES], int nodes) {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int nodes, start, end;
    int adjMatrix[MAX_NODES][MAX_NODES];

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    // Initialize the adjacency matrix
    initializeMatrix(adjMatrix, nodes);

    // Input edges
    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);
        
        // Check for valid node range
        if (start >= 0 && start < nodes && end >= 0 && end < nodes) {
            addEdge(adjMatrix, start, end);
        } else {
            printf("Invalid node indices. Please enter valid nodes (0 to %d).\n", nodes - 1);
            i--;  // Repeat the current edge input
        }
    }

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    printMatrix(adjMatrix, nodes);

    return 0;
}
