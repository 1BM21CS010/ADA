#include<stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int W,int weights[],int values[],int n)
{
    int matrix[n+1][W+1];
    int i,j;
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<W+1; j++)
        {
            if(i==0 || j==0) matrix[i][j]=0;
            else if(weights[i]>j) matrix[i][j]=matrix[i-1][j];
            else {
                matrix[i][j]= max(matrix[i-1][j], matrix[i-1][j-weights[i]]+values[i]);
            }
        }
    }
    return matrix[n][W];
}

int main() {
    int W, n;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n];
    int values[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    int max_value = knapsack(W, weights, values, n);
    printf("Maximum value in the knapsack: %d\n", max_value);

    return 0;
}
