#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

typedef struct Node {
    char data[100];
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct HashTable {
    Node *heads[SIZE];
    Node *tails[SIZE];
} HashTable;

// new hash table
HashTable* newHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < SIZE; i++) {
        table->heads[i] = NULL;
        table->tails[i] = NULL;
    }
    return table;
}

// hash index
int hash(const char *data) {
    if (data[0] >= 'A' && data[0] <= 'Z') {
        return (data[0] - 'A') % SIZE;
    } else if (data[0] >= 'a' && data[0] <= 'z') {
        return (data[0] - 'a') % SIZE;
    }
    return 0; // default value
}

// create a new node
Node* newNode(const char *data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert function
void insert(HashTable* table, const char *data) {
    Node* temp = newNode(data);
    const int index = hash(data);

    if (table->heads[index] == NULL) {
        // Empty bucket
        table->heads[index] = table->tails[index] = temp;
    } else {
        // Insert in sorted order
        if (strcmp(table->heads[index]->data, temp->data) >= 0) {
            // Insert at head
            temp->next = table->heads[index];
            table->heads[index]->prev = temp;
            table->heads[index] = temp;
        } else if (strcmp(table->tails[index]->data, temp->data) <= 0) {
            // Insert at tail
            temp->prev = table->tails[index];
            table->tails[index]->next = temp;
            table->tails[index] = temp;
        } else {
            // Insert in middle
            Node* curr = table->heads[index];
            while (curr != NULL && strcmp(curr->data, data) <= 0) {
                curr = curr->next;
            }
            temp->prev = curr->prev;
            temp->next = curr;
            curr->prev->next = temp;
            curr->prev = temp;
        }
    }
}

// Delete function
void delete(HashTable* table, const char *data) {
    int index = hash(data);
    if (table->heads[index] == NULL) {
        return;
    }
    if (strcmp(table->heads[index]->data, data) == 0) {
        // Delete from head
        Node* temp = table->heads[index];
        table->heads[index] = temp->next;

        if (table->heads[index] == NULL) {
            table->tails[index] = NULL;
        } else {
            table->heads[index]->prev = NULL;
        }
        free(temp);
    } else if (strcmp(table->tails[index]->data, data) == 0) {
        // Delete from tail
        Node* temp = table->tails[index];
        table->tails[index] = temp->prev;
        table->tails[index]->next = NULL;
        free(temp);
    } else {
        // Delete from middle
        Node* curr = table->heads[index];
        while (curr != NULL && strcmp(curr->data, data) != 0) {
            curr = curr->next;
        }
        if (curr != NULL) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
        }
    }
}

// Print function
void printTable(HashTable* table) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);

        if (table->heads[i] == NULL) {
            printf("-\n");
        } else {
            Node* curr = table->heads[i];
            while (curr != NULL) {
                printf("%s -> ", curr->data);
                curr = curr->next;
            }
            printf("NULL\n");
        }
    }
}

// Example usage
int main() {
    HashTable* table = newHashTable();
    insert(table, "Andre");
    insert(table, "Andri");
    insert(table, "Andro");
    insert(table, "Budi");
    delete(table, "Andro");
    printTable(table);
    return 0;
}