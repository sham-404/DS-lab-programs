/* circular_queue.c
   Menu-driven circular queue implementation using an array
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queueArr[SIZE];
int front = -1;
int rear = -1;


void enqueue(int x) {
    if (front == (rear + 1) % SIZE) {
        printf("\nQueue Overflow! Cannot insert %d\n", x);
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queueArr[rear] = x;
    printf("\nInserted %d into queue.\n", x);
}

int dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow! Nothing to delete.\n");
        return -1;
    }
    int val = queueArr[front];
    if (front == rear) {
        // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("\nDeleted %d from queue.\n", val);
    return val;
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queueArr[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nOperations performed by Circular Queue\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("Enter the choice: ");

        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                if (scanf("%d", &value) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Invalid input.\n");
                    break;
                }
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("\nInvalid choice!!\n");
                break;
        }
    }

    return 0;
}
