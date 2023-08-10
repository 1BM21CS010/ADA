#include<stdio.h>

#define MAX_VERTICES 20

int a[MAX_VERTICES][MAX_VERTICES], q[MAX_VERTICES], visited[MAX_VERTICES];
int n, f, r;

void bfs(int v) {
    int i;
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
            visited[i] = 1;
        }
    }
    if (f <= r) {
        bfs(q[f++]);
    }
}

int main() {
    int v, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    f = 0;
    r = -1;
    visited[v] = 1;
    bfs(v);

    printf("The nodes that are reachable are:\n");

    int allNodesReachable = 1;
    for (i = 1; i <= n; i++) {
        if (visited[i]) {
            printf("%d\t", i);
        } else {
            printf("\nBFS is not possible. Not all nodes are reachable.\n");
            allNodesReachable = 0;
            break;
        }
    }

    if (allNodesReachable) {
        printf("\n");
    }

    return 0;
}
