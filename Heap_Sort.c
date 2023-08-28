#include<stdio.h>

void heapsort(int n, int arr[])
{
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n,arr,i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root (maximum value) to the end
        swap(&arr[0], &arr[i]);
        // Call max heapify on the reduced heap
        heapify(i, arr, 0);
    }
}

void heapify(int n, int arr[], int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(n, arr, largest);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int n;
    printf("HEAP SORT \n ");
    printf("\nEnter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapsort(n, arr);

    printf("\nSorted array in ascending order:\n ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
