#include <stdio.h>
#include <stdlib.h>




void merge(int low, int mid ,int high,int *a)
{
    int c[100];
    int i = low;
    int j= mid+1;
    int k= 0;
    while(i<=mid && j<= high)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i+=1;
            k+=1;
        }
        else
        {
            c[k]=a[j];
            j=j+1;
            k=k+1;
        }
    }
    while(i<=mid)
    {
        c[k]=a[i];
        k=k+1;
        i=i+1;
    }
    while(j<=high)
    {
        c[k]=a[j];
        k=k+1;
        j=j+1;
    }
    for(i=0; i<high-low+1; i++){
        a[i+low]=c[i];
    }
}
void merge_sort(int low, int high, int *a)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(low ,mid ,a);
        merge_sort(mid+1, high,a);
        merge(low , mid, high,a);
    }
}
void main()
{
    int a[100], i, low, high;

    printf("Enter the array to be sorted: ");
    for(i=0; i<10; i++)
        scanf("%d", &a[i]);
    low=0;
    high=9;
    merge_sort(low, high,a);
    printf("The sorted array is: ");
        for(i=0; i<10; i++)
        printf("%d  ", a[i]);

}

