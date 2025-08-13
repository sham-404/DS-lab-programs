/* queue_linked_list.c
   Queue implementation using Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void push(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("\nMemory allocation failed.\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("\nInserted %d into the queue.\n", value);
}

void pop() {
    if (front == NULL) {
        printf("\nQueue is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = front;
    printf("\nDeleted %d from the queue.\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("\nQueue elements (front -> rear):\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Push (Enqueue)\n");
        printf("2. Pop (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a value to push into queue: ");
                if (scanf("%d", &value) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Invalid input.\n");
                    break;
                }
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice!!\n");
                break;
        }
    }

    return 0;
}
