#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int key;
    char val[50];
    struct Node *next;
};

void push(struct Node **head, int key, char value[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> key = key;
    strcpy(newNode -> val, value);
    newNode -> next = *head;
    *head = newNode;
}

void pop(struct Node **head, int key) {
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while(temp != NULL && temp -> key != key) {
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL) {
        return;
    }
    if(prev == NULL) {
        *head = temp -> next;
    } else {
        prev -> next = temp -> next;
    }
    free(temp);
}

void printAll(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%s ", temp -> val);
        temp = temp -> next;
    }
}

int main() {
    struct Node *list = NULL;
    push(&list, 1, "hello");
    push(&list, 2, "hi");
    pop(&list, 1);
    printAll(list);
    return 0;
}