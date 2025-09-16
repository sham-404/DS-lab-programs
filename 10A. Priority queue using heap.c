#include <stdio.h>
#define MAX 100

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void insert(int heap[], int *heapsize, int data) {
    if(*heapsize == MAX) {
        printf("Queue is Full!!\n");
        return;
    }

    int i = *heapsize;
    heap[i] = data;
    (*heapsize)++;

    // Bubble up
    while(i > 0 && heap[parent(i)] < heap[i]) {
        swap(&heap[parent(i)], &heap[i]);
        i = parent(i);
    }
}

int del_hi_priori(int heap[], int *heapsize) {
    if(*heapsize == 0) {
        printf("Queue is Empty!!\n");
        return 0;
    }

    int max = heap[0];
    heap[0] = heap[*heapsize - 1];
    (*heapsize)--;

    // Heapify down
    int i = 0;
    while(1) {
        int l = left(i);
        int r = right(i);
        int max_child;

        if(l >= *heapsize)
            break;
        if(r >= *heapsize)
            max_child = l;
        else
            max_child = (heap[l] > heap[r]) ? l : r;

        if(heap[i] >= heap[max_child])
            break;

        swap(&heap[i], &heap[max_child]);
        i = max_child;
    }

    return max;
}

void display(int heap[], int heapsize) {
    if(heapsize == 0) {
        printf("Queue is Empty!!\n");
        return;
    }
    for(int i = 0; i < heapsize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[MAX], heapsize = 0;
    int choice, data;

    while(1) {
        printf("\n.....MAIN MENU.....\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insert(heap, &heapsize, data);
                break;
            case 2: {
                int val = del_hi_priori(heap, &heapsize);
                if(val != 0)
                    printf("The deleted value is: %d\n", val);
                break;
            }
            case 3:
                display(heap, heapsize);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
