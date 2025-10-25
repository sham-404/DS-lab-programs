#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE];  // Hash table

// Initialize the hash table
void initialize() {
    int i; for (i= 0; i < TABLE_SIZE; i++)
        h[i] = -1;  // Using -1 to indicate empty slot
}

// Insert a key into the hash table using linear probing
void insert() {
    int key, index, i, hkey;
    printf("\nEnter a value to insert into the hash table: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == -1) {  // Empty slot
            h[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
    }

    printf("Hash table is full! Cannot insert %d\n", key);
}

// Search for a key in the hash table
void search() {
    int key, index, i, hkey;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == key) {
            printf("Value %d is found at index %d\n", key, index);
            return;
        }
        if (h[index] == -1)  // Empty slot, key not present
            break;
    }

    printf("Value %d is not found in the hash table\n", key);
}

// Display the hash table
void display() {
    printf("\nElements in the hash table are:\n");
    int i; for (i= 0; i < TABLE_SIZE; i++)
        if (h[i] != -1)
            printf("Index %d: %d\n", i, h[i]);
        else
            printf("Index %d: Empty\n", i);
}

int main() {
    int opt;

    initialize();  // Initialize hash table

    while (1) {
        printf("\nPress 1.Insert\t2.Display\t3.Search\t4.Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}
