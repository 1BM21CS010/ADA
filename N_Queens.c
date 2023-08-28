#include <stdio.h>
#define MAX 10
int x[MAX],c=0;
//x[] is global array with first (k-1) values already set.
//Input: k - the queen k
// x[k]- position of queen k
int place(int k)
{
    int i;
    for (i = 1; i < k; i++)
        {
        if (x[i] == x[k] || i - x[i] == k - x[k] || i + x[i] == k + x[k])
        {
            return 0;
        }
    }
    return 1;
}

void write(int n)
{
    c++;
    printf("\nSolution %d: \n\n",c);
    for (int i = 1; i <= n; i++)//i-> queen number
        {
        for (int j = 1; j <= n; j++)//j-> position
        {
            if (j == x[i])
                printf("Q%d\t",i);
            else
                printf("_\t");
        }
        printf("\n\n");
    }
    printf("\n");
}

void nqueens(int n)
{
    int k = 1; //Select the first queen
    x[k] = 0;//But not placed on chess board

    while (k != 0) //A queen exists ?
    {
        x[k] = x[k] + 1;//Place the kth queen in next column

        while (x[k] <= n && !place(k))
        {
            x[k] = x[k] + 1;
        }
        //If queen successfully placed ?
        if (x[k] <= n)
        {
            if (k == n)  //If all Queens are placed
            {
                write(n);
            }
            else
            {
                k = k + 1;  //Select next Queen
                x[k] = 0; //But do not place
            }
        }

        else
            k = k - 1; //Backtrack and select previous queen
    }
}

int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    nqueens(n);
    return 0;
}
