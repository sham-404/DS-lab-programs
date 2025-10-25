#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } int;

typedef struct node {
    int info;
    int balance;  // Balance factor: -1,0,1
    struct node* lchild;
    struct node* rchild;
} node;

// Function prototypes
node* insert(int info, node* pptr, int* ht_inc);
node* search(node* ptr, int info);
void display(node* ptr, int level);
void inorder(node* ptr);

// Main function
int main() {
    node* root = NULL;
    int choice, info;
    int ht_inc;

    while(1) {
        printf("\n1. Insert\n2. Display\n3. Inorder Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &info);
                if(search(root, info) == NULL) {
                    root = insert(info, root, &ht_inc);
                } else {
                    printf("Duplicate value ignored\n");
                }
                break;
            case 2:
                if(root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("AVL Tree:\n");
                    display(root, 1);
                }
                break;
            case 3:
                if(root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}

// Search for a node
node* search(node* ptr, int info) {
    if(ptr == NULL)
        return NULL;
    if(info < ptr->info)
        return search(ptr->lchild, info);
    else if(info > ptr->info)
        return search(ptr->rchild, info);
    else
        return ptr;
}

// Right rotation
node* rotateRight(node* p) {
    node* l = p->lchild;
    p->lchild = l->rchild;
    l->rchild = p;
    return l;
}

// Left rotation
node* rotateLeft(node* p) {
    node* r = p->rchild;
    p->rchild = r->lchild;
    r->lchild = p;
    return r;
}

// AVL insertion
node* insert(int info, node* pptr, int* ht_inc) {
    if(pptr == NULL) {
        pptr = (node*)malloc(sizeof(node));
        pptr->info = info;
        pptr->lchild = pptr->rchild = NULL;
        pptr->balance = 0;
        *ht_inc = TRUE;
        return pptr;
    }

    if(info < pptr->info) {
        pptr->lchild = insert(info, pptr->lchild, ht_inc);
        if(*ht_inc) {
            switch(pptr->balance) {
                case 1: // Left heavy
                    if(pptr->lchild->balance == 1) { // LL rotation
                        pptr = rotateRight(pptr);
                        pptr->balance = 0;
                        pptr->rchild->balance = 0;
                    } else { // LR rotation
                        pptr->lchild = rotateLeft(pptr->lchild);
                        pptr = rotateRight(pptr);
                        pptr->lchild->balance = 0;
                        pptr->rchild->balance = 0;
                        pptr->balance = 0;
                    }
                    *ht_inc = FALSE;
                    break;
                case 0:
                    pptr->balance = 1;
                    break;
                case -1:
                    pptr->balance = 0;
                    *ht_inc = FALSE;
                    break;
            }
        }
    } else if(info > pptr->info) {
        pptr->rchild = insert(info, pptr->rchild, ht_inc);
        if(*ht_inc) {
            switch(pptr->balance) {
                case -1: // Right heavy
                    if(pptr->rchild->balance == -1) { // RR rotation
                        pptr = rotateLeft(pptr);
                        pptr->balance = 0;
                        pptr->lchild->balance = 0;
                    } else { // RL rotation
                        pptr->rchild = rotateRight(pptr->rchild);
                        pptr = rotateLeft(pptr);
                        pptr->lchild->balance = 0;
                        pptr->rchild->balance = 0;
                        pptr->balance = 0;
                    }
                    *ht_inc = FALSE;
                    break;
                case 0:
                    pptr->balance = -1;
                    break;
                case 1:
                    pptr->balance = 0;
                    *ht_inc = FALSE;
                    break;
            }
        }
    }

    *ht_inc = TRUE;
    return pptr;
}

// Display tree sideways
void display(node* ptr, int level) {
    int i;
    if(ptr != NULL) {
        display(ptr->rchild, level + 1);
        printf("\n");
        for(i = 0; i < level; i++)
            printf("   ");
        printf("%d\n", ptr->info);
        display(ptr->lchild, level + 1);
    }
}

// Inorder traversal
void inorder(node* ptr) {
    if(ptr != NULL) {
        inorder(ptr->lchild);
        printf("%d ", ptr->info);
        inorder(ptr->rchild);
    }
}
