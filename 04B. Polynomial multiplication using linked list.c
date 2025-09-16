/* polynomial_multiply.c
   Polynomial multiplication using singly linked list
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

void insertTerm(struct Node **poly, int coeff, int pow) {
    struct Node *temp = *poly, *prev = NULL;

    // Merge with existing term if same power
    while (temp != NULL && temp->pow > pow) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->pow == pow) {
        temp->coeff += coeff;
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = temp;

    if (prev == NULL) {
        *poly = newNode;
    } else {
        prev->next = newNode;
    }
}

void multiply(struct Node *poly1, struct Node *poly2, struct Node **result) {
    struct Node *ptr1, *ptr2;

    *result = NULL;

    if (poly1 == NULL || poly2 == NULL)
        return;

    for (ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int pow = ptr1->pow + ptr2->pow;
            insertTerm(result, coeff, pow);
        }
    }
}

int main(void) {
    struct Node *poly1 = NULL, *poly2 = NULL, *prod = NULL;

    printf("Enter first polynomial:\n");
    create(&poly1);
    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("\nEnter second polynomial:\n");
    create(&poly2);
    printf("\nSecond Polynomial: ");
    display(poly2);

    multiply(poly1, poly2, &prod);
    printf("\nProduct of Polynomials: ");
    display(prod);

    return 0;
}
