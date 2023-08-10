#include <stdio.h>

void swap(int *a, int *b) { // to swap the largest nuber with the next number
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void johnsonT(int *array, int *directions, int n) {
    display(array, n);

    int mobileElement, mobileIndex;

    while (1) {
        mobileElement = 0;
        mobileIndex = 0;

        for (int i = 0; i < n; i++) {
            if ((i == 0 && directions[i] == -1) ||
                (i == n - 1 && directions[i] == 1)) {
                continue;
            }

            if ((array[i] > array[i + directions[i]]) &&
                (array[i] > mobileElement)) {
                mobileElement = array[i];
                mobileIndex = i;
            }
        }

        if (mobileElement == 0) {
            break;
        }

        int neighborIndex = mobileIndex + directions[mobileIndex];
        swap(&array[mobileIndex], &array[neighborIndex]);
        swap(&directions[mobileIndex], &directions[neighborIndex]);

        for (int i = 0; i < n; i++) {
            if (array[i] > mobileElement) {
                directions[i] = -directions[i];
            }
        }

        display(array, n);
    }
}

int main() {
    int n;

    printf("Enter the n of the array: ");
    scanf("%d", &n);

    int array[n];
    int directions[n];

    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
        directions[i] = -1;
    }

    johnsonT(array, directions, n);

    return 0;
}
