#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Output array to hold the shortest distance from src to i
    bool visited[V]; // Array to mark visited vertices

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0; // Distance from source to itself is 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 7, 0},
        {3, 0, 4, 2, 0},
        {0, 4, 0, 5, 6},
        {7, 2, 5, 0, 4},
        {0, 0, 6, 4, 0}
    };

    int source = 0; // Source vertex
    dijkstra(graph, source);

    return 0;
}

