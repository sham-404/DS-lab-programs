#include <stdio.h>
#include <stdlib.h>

typedef struct bst {
    int data;
    struct bst *left, *right;
} node;

// Function prototypes
node* getNode();
void insert(node **root, node *New);
node* search(node *root, int key, node **parent);
node* deleteNode(node *root, int key);
void inorder(node *root);

int main() {
    node *root = NULL;
    int choice, key;
    char ans;

    do {
        printf("\n1. Create/Insert\n2. Search\n3. Delete\n4. Display (Inorder)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Insert
                do {
                    node *s = getNode();
                    printf("Enter element: ");
                    scanf("%d", &s->data);
                    insert(&root, s);
                    printf("Do you want to enter more elements? (y/n): ");
                    scanf(" %c", &ans);
                } while(ans == 'y' || ans == 'Y');
                break;

            case 2: // Search
                printf("Enter element to search: ");
                scanf("%d", &key);
                node *parent = NULL;
                node *found = search(root, key, &parent);
                if(found) {
                    printf("Element %d found.\n", key);
                    if(parent)
                        printf("Parent of node %d is %d\n", key, parent->data);
                    else
                        printf("The node is root and has no parent.\n");
                } else {
                    printf("Element %d not found.\n", key);
                }
                break;

            case 3: // Delete
                printf("Enter element to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 4: // Display
                if(root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);

    return 0;
}

// Create a new node
node* getNode() {
    node *temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
void insert(node **root, node *New) {
    if(*root == NULL) {
        *root = New;
        return;
    }
    if(New->data < (*root)->data)
        insert(&(*root)->left, New);
    else if(New->data > (*root)->data)
        insert(&(*root)->right, New);
    else
        printf("Duplicate element ignored.\n");
}

// Search in BST
node* search(node *root, int key, node **parent) {
    node *temp = root;
    *parent = NULL;
    while(temp) {
        if(key == temp->data)
            return temp;
        *parent = temp;
        if(key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

// Delete node in BST
node* deleteNode(node *root, int key) {
    if(root == NULL) return NULL;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if(root->left == NULL) {
            node *temp = root->right;
            free(root);
            printf("Deleted %d\n", key);
            return temp;
        } else if(root->right == NULL) {
            node *temp = root->left;
            free(root);
            printf("Deleted %d\n", key);
            return temp;
        } else {
            // Node with two children: find inorder successor
            node *succParent = root;
            node *succ = root->right;
            while(succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            root->data = succ->data; // Copy successor's data

            if(succParent != root)
                succParent->left = deleteNode(succParent->left, succ->data);
            else
                succParent->right = deleteNode(succParent->right, succ->data);
        }
    }
    return root;
}

// Inorder traversal
void inorder(node *root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
