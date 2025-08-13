/* polynomial_add.c
   Polynomial addition using singly linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

void create(struct Node **poly) {
    int coeff, pow, cont;
    struct Node *temp, *newNode;

    *poly = NULL;

    do {
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter power: ");
        scanf("%d", &pow);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = coeff;
        newNode->pow = pow;
        newNode->next = NULL;

        if (*poly == NULL) {
            *poly = newNode;
        } else {
            temp = *poly;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        printf("Add another term? (1 = Yes, 0 = No): ");
        scanf("%d", &cont);

    } while (cont == 1);
}

void display(struct Node *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

void polyAdd(struct Node *poly1, struct Node *poly2, struct Node **poly) {
    struct Node *temp, *newNode;

    *poly = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if (poly1->pow > poly2->pow) {
            newNode->coeff = poly1->coeff;
            newNode->pow = poly1->pow;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            newNode->coeff = poly2->coeff;
            newNode->pow = poly2->pow;
            poly2 = poly2->next;
        }
        else {
            newNode->coeff = poly1->coeff + poly2->coeff;
            newNode->pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (*poly == NULL) {
            *poly = newNode;
        } else {
            temp = *poly;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    /* Add remaining terms */
    while (poly1 != NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = poly1->coeff;
        newNode->pow = poly1->pow;
        newNode->next = NULL;

        temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;

        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = poly2->coeff;
        newNode->pow = poly2->pow;
        newNode->next = NULL;

        temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;

        poly2 = poly2->next;
    }
}

int main(void) {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    printf("Enter first polynomial:\n");
    create(&poly1);
    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("\nEnter second polynomial:\n");
    create(&poly2);
    printf("\nSecond Polynomial: ");
    display(poly2);

    polyAdd(poly1, poly2, &sum);
    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}
