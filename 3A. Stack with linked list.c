/* stack_linked_list.c
   Stack ADT implementation using Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *ptr;
};

struct Node *top = NULL;
int count = 0;

void create() {
    top = NULL;
    count = 0;
    printf("\nStack created.\n");
}

void push(int data) {
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("\nMemory allocation failed.\n");
        return;
    }
    temp->info = data;
    temp->ptr = top;
    top = temp;
    count++;
    printf("\nPushed %d onto stack.\n", data);
}

void pop() {
    struct Node *temp;
    if (top == NULL) {
        printf("\nError: Trying to pop from empty stack.\n");
        return;
    }
    temp = top;
    top = top->ptr;
    printf("\nPopped value: %d\n", temp->info);
    free(temp);
    count--;
}

int topelement() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return -1;
    }
    return top->info;
}

void empty() {
    if (top == NULL)
        printf("\nStack is empty.\n");
    else
        printf("\nStack is not empty with %d elements.\n", count);
}

void display() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack elements (top -> bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->ptr;
    }
}

void stack_count() {
    printf("\nNo. of elements in stack: %d\n", count);
}

void destroy() {
    struct Node *temp;
    while (top != NULL) {
        temp = top;
        top = top->ptr;
        free(temp);
    }
    count = 0;
    printf("\nStack destroyed.\n");
}

int main(void) {
    int ch, no;

    create();

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top element\n");
        printf("4. Check empty\n");
        printf("5. Display\n");
        printf("6. Stack count\n");
        printf("7. Destroy stack\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input.\n");
            continue;
        }

        switch (ch) {
            case 1:
                printf("Enter data: ");
                if (scanf("%d", &no) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Invalid input.\n");
                    break;
                }
                push(no);
                break;
            case 2:
                pop();
                break;
            case 3:
                no = topelement();
                if (no != -1)
                    printf("Top element: %d\n", no);
                break;
            case 4:
                empty();
                break;
            case 5:
                display();
                break;
            case 6:
                stack_count();
                break;
            case 7:
                destroy();
                break;
            case 8:
                printf("Exiting.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Wrong choice, please enter correct choice.\n");
                break;
        }
    }

    return 0;
}
