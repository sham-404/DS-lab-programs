/* stack_array.c
   Simple array-based stack with menu: Push, Pop, Show, Exit
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stackArr[SIZE];
int top = -1;

void push(int x) {
    if (top == SIZE - 1) {
        printf("\nStack Overflow! Cannot push %d\n", x);
        return;
    }
    stackArr[++top] = x;
    printf("\nPushed %d onto stack.\n", x);
}

int pop() {
    if (top == -1) {
        printf("\nStack Underflow! Nothing to pop.\n");
        return -1; /* sentinel; caller should be aware */
    }
    int val = stackArr[top--];
    printf("\nPopped %d from stack.\n", val);
    return val;
}

void show() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack (top -> bottom):\n");
    for (int i = top; i >= 0; --i) {
        printf("%d\n", stackArr[i]);
    }
}


int main(void) {
    int choice;
    int value;

    while (1) {
        printf("\nOperations performed by Stack\n");
        printf("1. Push the element\n");
        printf("2. Pop element\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            /* clear invalid input */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to be pushed: ");
                if (scanf("%d", &value) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) { }
                    printf("Invalid input.\n");
                    break;
                }
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                show();
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
