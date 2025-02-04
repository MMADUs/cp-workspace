#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    char value[20];
    struct node *next;
};

void insert(struct node **head, const int k, const char v[]) {
    // the casting '(struct node*)' is only required in CPP
    // because malloc returns void, so casting is mandatory for its type
    // eg: (struct node*)malloc(sizeof(struct node));
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> key = k;
    strcpy(newNode -> value, v);
    newNode -> next = *head;
    *head = newNode;
}

void insertAt(struct node **head, const int position, const int k, const char v[]) {
    // if at start position (0)
    if(position == 0) {
        insert(head, k, v);
        return;
    }
    // set head based on position
    struct node *current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current -> next;
    }
    if(current == NULL) {
        // position out of bounds
        return;
    }
    // insert the new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> key = k;
    strcpy(newNode -> value, v);
    newNode -> next = current -> next;
    current -> next = newNode;
}

void insertAtEnd(struct node **head, const int k, const char v[]) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> key = k;
    strcpy(newNode -> value, v);
    newNode -> next = NULL;
    // if list is empty, new node becomes head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // otherwise find the last node
    struct node *current = *head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    // insert the new node after the last node
    current -> next = newNode;
}

struct node* get(struct node *head, const int k) {
    // set the current head
    struct node* current = head;
    // search linearly
    while (current != NULL) {
        if (current -> key == k) {
            return current;
        }
        current = current -> next;
    }
    return NULL;
}

void delete(struct node *head, const int k) {
    // set the current nod head
    struct node *current = head;
    // find & delete by key
    while(current != NULL) {
        if (current -> key == k) {
            struct node *del = current;
            current = current -> next;
            free(del);
            return;
        } else {
            current = current -> next;
        }
    }
}

void printNode(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("key: %d value: %s\n", current -> key, current -> value);
        current = current -> next;
    }
}

int main() {
    // init first empty head
    struct node *head = NULL;
    // insert
    insert(&head, 1, "hello");
    insert(&head, 2, "world");
    insert(&head, 3, "nizwa");
    // get
    struct node *found = get(head, 2);
    if (found != NULL) {
        printf("found with key: %d value: %s\n", found -> key, found -> value);
    }
    // delete
    delete(&head, 2);
    struct node *deleted = get(head, 2);
    if (deleted != NULL) {
        printf("found with key: %d value: %s\n", deleted -> key, deleted -> value);
    }
    // insert on position
    insertAt(&head, 1, 7, "this is middle");
    insertAtEnd(&head, 10, "the end");
    // print all
    printNode(head);
    return 0;
}
