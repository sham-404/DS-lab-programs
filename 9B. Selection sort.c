#include <stdio.h>

int* selectionSort(int array[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(array[i] > array[j]) {
                // Swap
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
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

    int* sortedArray = selectionSort(array, n);

    printf("Sorted list:\n");
    for(i = 0; i < n; i++)
        printf("%d  ", sortedArray[i]);

    printf("\n");
    return 0;
}
