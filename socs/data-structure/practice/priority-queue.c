#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int priority;
    char name[50];
    struct node *next;
}node;

typedef struct SLL {
    node *head;
}queue;

queue *newQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    return q;
}

int getPriority(const char *classifier) {
    if (strcmp(classifier, "KAYA") == 0) return 1;
    if (strcmp(classifier, "GANTENG") == 0) return 2;
    if (strcmp(classifier, "BAIK") == 0) return 3;
    return 4;
}

node *newNode(const char *name, const char *classifier) {
    node *n = (node *)malloc(sizeof(node));
    n->priority = getPriority(classifier);
    strcpy(n->name, name);
    n->next = NULL;
    return n;
}

void push(queue *q, const char *name, const char *classifier) {
    node *n = newNode(name, classifier);
    if(q->head == NULL || n->priority < q->head->priority) {
        n->next = q->head;
        q->head = n;
        return;
    }
    node *curr = q->head;
    while(curr->next != NULL && n->priority >= curr->next->priority) {
        curr = curr->next;
    }
    n->next = curr->next;
    curr->next = n;
}

void pop(queue *q) {
    if(q->head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node *n = q->head;
    printf("Popping: %s\n", n -> name);
    q->head = n->next;
    free(n);
}

void printAll(const queue *q) {
    node *curr = q->head;
    while(curr != NULL) {
        printf("Name: %s\n", curr -> name);
        curr = curr -> next;
    }
}

int main() {
    queue *q = newQueue();
    pop(q);
    push(q, "Danielson", "KAYA");
    push(q, "Nizwa", "GANTENG");
    push(q, "Andrian", "BAIK");
    push(q, "Jason", "KAYA");
    push(q, "Jeremy", "BAIK");
    push(q, "Tristan", "aneh aowkaok");
    push(q, "Pandu", "KAYA");
    printAll(q);
    pop(q);
    printAll(q);
    return 0;
}