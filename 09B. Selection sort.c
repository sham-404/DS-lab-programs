#include <stdio.h>

int* selectionSort(int array[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) minIndex = j;
        }

        // Swap once per pass
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }

    return array;
}

int main() {
    int array[1000], n, i;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &array[i]);

    int* sortedArray = selectionSort(array, n);

    printf("\nSorted list:\n");
    for (i = 0; i < n; i++) printf("%d  ", sortedArray[i]);

    printf("\n");
    return 0;
}
