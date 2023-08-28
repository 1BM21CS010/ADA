/*Implement All Pair Shortest paths problem using Floyd’s algorithm.*/

#include<stdio.h>
#define MAX 10
#define INF 999

void printSolution(int n,int dist[MAX][MAX])
{
    printf("The following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d ", dist[i][j]);
        }
        printf("\n");
    }
    //printf("\n The shortest paths are:\n");
    //for(int i=1;i<=n;i++)
        //for(int j=1;j<=n;j++)
            //{
                //if(i!=j)
                   //printf("\n <%d,%d>=%d",i,j,dist[i][j]);
            //}
}

void floyd(int n,int dist[MAX][MAX])
{
    int i, j, k;

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(n,dist);
}

void main()
{
    int i,n,W,j;
    int w[MAX][MAX];

    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the weight matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%d",&w[i][j]);
    }
    floyd(n,w);
}



