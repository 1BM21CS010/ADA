#include <stdio.h>
#include <stdlib.h>

int partition(int low, int high, int* a) {
    int i = low;
    int j = high + 1;
    int pivot = a[low];
    int temp;

    while (1) {
        do {
            i = i + 1;
        } while (pivot >= a[i]);

        do {
            j = j - 1;
        } while (pivot < a[j]);

        if (i >= j)
            break;

        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void Quicksort(int low, int high, int* a) {
    int j;

    if (low < high) {
        j = partition(low, high, a);
        Quicksort(low, j - 1, a);
        Quicksort(j + 1, high, a);
    }
}

int main() {
    int arr[20], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Quicksort(0, n - 1, arr);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
