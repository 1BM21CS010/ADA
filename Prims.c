// A C program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 10

int minKey(int key[], bool mstSet[], int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int printMST(int parent[], int graph[V][V], int n)
{
    int sum=0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        sum+=graph[i][parent[i]];
         printf("%d - %d \t%d \n", parent[i], i,
    graph[i][parent[i]]);
    }
    printf("Minimum Weight = %d \n",sum);
}

void MSTPrims(int graph[V][V],int n)
{
    int parent[V];
    int key[V];
    bool mstSet[V];//stores node included in mst

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;//all key set to infinte and all nodes not added

    key[0] = 0;//Make key 0 so that this vertex is picked as first
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);//stores min index
        mstSet[u] = true;

        for (int v = 0; v < n; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, n);
}

int main()
{
    int w[V][V],n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the weight matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&w[i][j]);
    }

    MSTPrims(w,n);

return 0;
}
