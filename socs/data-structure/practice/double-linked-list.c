#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *next;
    struct node *prev;
}node;

typedef struct double_linked_list {
    node *head;
    node *tail;
}DLL;

DLL *newDLL() {
    DLL *newDLL = (DLL *)malloc(sizeof(DLL));
    newDLL->head = NULL;
    newDLL->tail = NULL;
    return newDLL;
}

node *newNode(const int key) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void pushf(DLL *list, const int key) {
    node *n = newNode(key);
    if(list->head == NULL) {
        list->head = n;
        list->tail = n;
    } else {
        n->next = list->head;
        list->head->prev = n;
        list->head = n;
    }
}

void pushb(DLL *list, const int key) {
    node *n = newNode(key);
    if(list->head == NULL) {
        list->head = n;
        list->tail = n;
    } else {
        list->tail->next = n;
        n->prev = list->tail;
        list->tail = n;
    }
}

void push_asc(DLL *list, const int key) {
    node *n = newNode(key);
    if(list->head == NULL) {
        list->head = n;
        list->tail = n;
        return;
    }
    if(key < list->head->key) {
        n->next = list->head;
        list->head->prev = n;
        list->head = n;
        return;
    }
    node *curr = list->head;
    while(curr->next != NULL && key > curr->next->key) {
        curr = curr->next;
    }
    if(curr->next == NULL) {
        curr->next = n;
        n->prev = curr;
        list->tail = n;
    } else {
        n->next = curr->next;
        n->prev = curr;
        curr->next->prev = n;
        curr->next = n;
    }
}

void pop(DLL *list, const int k) {
    node *curr = list->head;
    while(curr != NULL && curr->key != k) {
        curr = curr->next;
    }
    if(curr == NULL) {
        printf("deleting element key: %d not found\n", k);
        return;
    }
    if(curr->prev == NULL) {
        list->head = curr->next;
    } else {
        curr->prev->next = curr->next;
    }
    if(curr->next == NULL) {
        list->tail = curr->prev;
    } else {
        curr->next->prev = curr->prev;
    }
    free(curr);
}

void display_forward(const DLL *list) {
    const node *curr = list->head;
    printf("Forward display: ");
    while(curr != NULL) {
        printf("%d ", curr->key);
        curr = curr->next;
    }
    printf("\n");
}

void display_backward(const DLL *list) {
    const node *curr = list->tail;
    printf("Backward display: ");
    while(curr != NULL) {
        printf("%d ", curr->key);
        curr = curr->prev;
    }
    printf("\n");
}

int main() {
    DLL *list = newDLL();
    pushf(list, 1);
    pushf(list, 2);
    pushb(list, 3);
    push_asc(list, 0);
    push_asc(list, 4);
    display_forward(list);
    display_backward(list);
    pop(list, 2);
    printf("After deleting 2:\n");
    display_forward(list);
    free(list);
    return 0;
}