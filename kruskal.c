#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
struct Edge {
    int source;
    int destination;
    int weight;
};

// Function prototypes
void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);
void unionSets(int parent[], int x, int y);
int find(int parent[], int vertex);

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (use -1 for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    kruskalMST(graph, vertices);

    return 0;
}

// Kruskal's algorithm for MST
void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    struct Edge edges[MAX_VERTICES * MAX_VERTICES]; // Max possible edges
    int edgesCount = 0;

    // Extract all the edges from the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (graph[i][j] != -1) {
                edges[edgesCount].source = i;
                edges[edgesCount].destination = j;
                edges[edgesCount].weight = graph[i][j];
                edgesCount++;
            }
        }
    }

    // Sort the edges in non-decreasing order of their weights
    for (int i = 0; i < edgesCount - 1; i++) {
        for (int j = 0; j < edgesCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    printf("Minimum Spanning Tree (MST) edges:\n");
    for (int i = 0; i < edgesCount; i++) {
        int srcParent = find(parent, edges[i].source);
        int destParent = find(parent, edges[i].destination);

        if (srcParent != destParent) {
            printf("%d - %d : %d\n", edges[i].source, edges[i].destination, edges[i].weight);
            unionSets(parent, srcParent, destParent);
        }
    }
}

//path compression)
int find(int parent[], int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find(parent, parent[vertex]);
    }
    return parent[vertex];
}

// Union by rank)
void unionSets(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    parent[yroot] = xroot;
}
