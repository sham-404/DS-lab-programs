#include <stdio.h>

int* insertionSort(int array[], int n) {
    int i, j, temp;
    for(i = 1; i < n; i++) {
        j = i;
        while(j > 0 && array[j] < array[j - 1]) {
            // Swap elements
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
    return array;
}

int main() {
    int array[1000], n, i;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);

    int *sortedArray = insertionSort(array, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d  ", sortedArray[i]);

    printf("\n");
    return 0;
}
