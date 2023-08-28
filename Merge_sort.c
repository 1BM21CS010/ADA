/*Sort a given set of N integer elements using Merge Sort technique and
compute its time taken. Run the program for different values of N and record
the time taken to sort.*/
#include<stdio.h>
//int array[20];
//int n;
void merge_sort(int low,int high,int n,int array[n])
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid,n,array);
        merge_sort(mid+1,high,n,array);
        merge(low,mid,high,n,array);
    }
}

void merge(int low,int mid,int high,int n,int array[n])
{
    int i=low,j=mid+1,k=low;
    int c[n];
    while(i<=mid&&j<=high)
    {
        if(array[i]<array[j])
        {
            c[k]=array[i];
            i++;
            k++;
        }
        else
        {
            c[k]=array[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        c[k]=array[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        c[k]=array[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        array[i]=c[i];
    }
}

void main()
{
    int i;
    int array[20],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    merge_sort(0,n-1,n,array);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
       // array[i]=c[i];
        printf("%d ", array[i]);
    }
}
