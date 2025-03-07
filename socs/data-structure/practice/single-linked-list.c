#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *next;
}node;

typedef struct single_linked_list {
    node *head;
}SLL;

SLL *newSLL() {
    SLL *newSLL = (SLL *)malloc(sizeof(SLL));
    newSLL->head = NULL;
    return newSLL;
}

node *newNode(const int key) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void pushf(SLL *list, const int key) {
    node *n = newNode(key);
    if(list->head == NULL) {
        list->head = n;
    } else {
        n->next = list->head;
        list->head = n;
    }
}

void pushb(const SLL *list, const int key) {
    node *n = newNode(key);
    node *curr = list->head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = n;
}

void push_asc(SLL *list, const int key) {
    node *n = newNode(key);
    if(list -> head == NULL || key < list -> head->key) {
        n->next = list->head;
        list->head = n;
        return;
    }
    node *curr = list->head;
    while(curr->next != NULL && key < curr->next->key) {
        curr = curr->next;
    }
    n->next = curr->next;
    curr->next = n;
}

void pop(SLL *list, const int k) {
    node *curr = list -> head;
    node *prev = NULL;
    while (curr != NULL && curr -> key != k) {
        prev = curr;
        curr = curr -> next;
    }
    if (curr == NULL) {
        printf("deleting element key: %d not found", k);
        return;
    }
    if (prev == NULL) {
        list -> head = curr -> next;
    } else {
        prev -> next = curr -> next;
    }
    free(curr);
}

void display(const SLL *list) {
    const node *curr = list -> head;
    while (curr != NULL) {
        printf("%d\n", curr -> key);
        curr = curr -> next;
    }
}

int main() {
    SLL *list = newSLL();
    pushf(list, 1);
    pushf(list, 2);
    pushb(list, 3);
    pop(list, 2);
    display(list);
    return 0;
}