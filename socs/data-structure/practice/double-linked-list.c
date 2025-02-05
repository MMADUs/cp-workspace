#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    char value[20];
    struct node *next;
    struct node *prev;
};

// insert in-front of the head
void insertHead(struct node **head, const int key, const char value[]) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key = key;
    strcpy(newNode->value, value);
    // points to the existing head
    newNode->next = *head;
    newNode->prev = NULL;
    // check if the insertion is the first head
    if (*head != NULL) {
        // points back to new node
        (*head)->prev = newNode;
    }
    // set the head to be the inserted node
    *head = newNode;
}

void insertTail(struct node **tail, const int key, const char value[]) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key = key;
    strcpy(newNode->value, value);
    // points to the existing tail
    newNode->next = NULL;
    newNode->prev = *tail;
    // check if the insertion is the first tail
    if (*tail != NULL) {
        // points back to new node
        (*tail)->next = newNode;
    }
    // set the tail to be the inserted node
    *tail = newNode;
}

void printNode(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("key: %d value: %s\n", current -> key, current -> value);
        current = current -> next;
    }
}

int main() {
    struct node *head = NULL;
    // insert
    insertHead(&head, 1, "hello");
    insertTail(&head, 2, "world");
    // print
    printNode(head);
    return 0;
}
