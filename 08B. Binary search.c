#include <stdio.h>

int main() {
    int c, first, last, middle, n, search, array[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers in sorted order:\n", n);
    for(c = 0; c < n; c++)
        scanf("%d", &array[c]);

    printf("Enter value to find: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    int found = 0;

    while(first <= last) {
        middle = (first + last) / 2;

        if(array[middle] < search)
            first = middle + 1;
        else if(array[middle] == search) {
            printf("%d found at location %d\n", search, middle + 1);
            found = 1;
            break;
        } else
            last = middle - 1;
    }

    if(!found)
        printf("Not found! %d is not present in the list\n", search);

    return 0;
}
