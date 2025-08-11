/* linked_list.c
   Singly Linked List with basic operations + sort() using insertion sort
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void createList(int n) {
    struct Node *temp, *newnode;
    int data, i;

    if (start != NULL) {
        printf("\nList is already created.\n");
        return;
    }

    printf("\nEnter data for node 1: ");
    scanf("%d", &data);

    start = (struct Node *)malloc(sizeof(struct Node));
    start->data = data;
    start->next = NULL;

    temp = start;
    for (i = 2; i <= n; i++) {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

    printf("\nThe list is created.\n");
}

void traverse() {
    struct Node *temp = start;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtFront(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = start;
    start = newnode;
}

void insertAtEnd(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = start;

    newnode->data = data;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAtPosition(int pos, int data) {
    struct Node *newnode, *temp;
    int i;

    if (pos == 1) {
        insertAtFront(data);
        return;
    }

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;

    temp = start;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nPosition out of range.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteFirst() {
    struct Node *temp;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    temp = start;
    start = start->next;
    free(temp);
}

void deleteEnd() {
    struct Node *temp, *prevnode;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }
    temp = start;
    while (temp->next != NULL) {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = NULL;
    free(temp);
}

void deletePosition(int pos) {
    struct Node *temp, *position;
    int i;

    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    temp = start;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("\nPosition out of range.\n");
        return;
    }

    position = temp->next;
    temp->next = position->next;
    free(position);
}

void maximum() {
    struct Node *temp = start;
    int max;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    max = temp->data;
    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    printf("\nMaximum number is: %d\n", max);
}

void mean() {
    struct Node *temp = start;
    int sum = 0, count = 0;
    float m;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    m = (float)sum / count;
    printf("\nMean is: %.2f\n", m);
}

void reverseList() {
    struct Node *prev = NULL, *current = start, *nextnode = NULL;
    while (current != NULL) {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    start = prev;
    printf("\nList reversed.\n");
}

/* Insertion sort on linked list */
void sort() {
    struct Node *current = start;
    struct Node *index = NULL;
    int temp;

    if (start == NULL) {
        printf("List is empty, nothing to sort.\n");
        return;
    }

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    printf("List sorted in ascending order.\n");
}




int main(void) {
    int choice, n, pos, data;

    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Create list\n");
        printf("2. Traverse\n");
        printf("3. Insert at front\n");
        printf("4. Insert at end\n");
        printf("5. Insert at position\n");
        printf("6. Delete first\n");
        printf("7. Delete end\n");
        printf("8. Delete position\n");
        printf("9. Maximum\n");
        printf("10. Mean\n");
        printf("11. Reverse\n");
        printf("12. Sort\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                insertAtPosition(pos, data);
                break;
            case 6:
                deleteFirst();
                break;
            case 7:
                deleteEnd();
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 9:
                maximum();
                break;
            case 10:
                mean();
                break;
            case 11:
                reverseList();
                break;
            case 12:
                sort();
                break;
            case 13:
                printf("Exiting.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
