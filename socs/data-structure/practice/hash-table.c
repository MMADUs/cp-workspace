#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define T_SIZE 27 // alphabet

typedef struct node {
    char name[50];
    struct node *next;
}node;

typedef struct hash_table {
    node *tables[T_SIZE];
}HT;

HT *new_hash_table() {
    HT *h = (HT *)malloc(sizeof(HT));
    for(int i = 0; i < T_SIZE; i++) {
        h->tables[i] = NULL;
    }
    return h;
}

node *newNode(const char *name) {
    node *n = (node *)malloc(sizeof(node));
    strcpy(n->name, name);
    n->next = NULL;
    return n;
}

int hash(const char *data) {
    if (data[0] >= 'A' && data[0] <= 'Z') {
        return (data[0] - 'A') % T_SIZE;
    }
    if (data[0] >= 'a' && data[0] <= 'z') {
        return (data[0] - 'a') % T_SIZE;
    }
    return 0;
}

void insert(HT *ht, const char *name) {
    node *n = newNode(name);
    const int index = hash(name);
    node *curr = ht->tables[index];
    if(curr == NULL) {
        ht->tables[index] = n;
        return;
    }
    if(strcmp(curr->name, name) > 0) {
        n->next = ht->tables[index];
        ht->tables[index] = n;
        return;
    }
    while(curr->next != NULL && strcmp(curr->next->name, name) < 0) {
        curr = curr->next;
    }
    n->next = curr->next;
    curr->next = n;
}

void delete(HT *ht, const char *name) {
    const int index = hash(name);
    node *curr = ht->tables[index];
    if(curr == NULL) {
        printf("No data on specified hashed table\n");
        return;
    }
    if(strcmp(curr->name, name) == 0) {
        ht->tables[index] = curr->next;
        printf("deleting: %s\n", curr->name);
        free(curr);
        return;
    }
    while(curr->next != NULL) {
        if(strcmp(curr->next->name, name) == 0) {
            node *temp = curr->next;
            curr->next = temp->next;
            free(temp);
            return;
        }
        curr = curr->next;
    }
    printf("Name not found: %s\n", name);
}

void display(const HT *ht) {
    for(int i = 0; i < T_SIZE; i++) {
        const char indexChar = (i < 26) ? ('A' + i) : '#';
        printf("%c: ", indexChar);
        node *curr = ht->tables[i];
        while(curr != NULL) {
            printf("%s -> ", curr->name);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HT *ht = new_hash_table();
    insert(ht, "Andi");
    insert(ht, "Ando");
    insert(ht, "Ande");
    insert(ht, "Budi");
    insert(ht, "Nizwa");
    display(ht);
    delete(ht, "Andi");
    display(ht);
    free(ht);
    return 0;
}