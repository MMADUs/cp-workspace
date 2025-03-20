#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *next;
  struct node *prev;
} node;

typedef struct double_linked_list {
  node *head;
  node *tail;
} DLL;

DLL *newDLL() {
  DLL *list = (DLL *)malloc(sizeof(DLL));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

node *newNode(const int key) {
  node *n = (node *)malloc(sizeof(node));
  n->key = key;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

void push_head(DLL *list, const int key) {
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

void push_tail(DLL *list, const int key) {
  node *n = newNode(key);
  if(list->tail == NULL) {
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
  } else if(key < list->head->key) {
    n->next = list->head;
    list->head->prev = n;
    list->head = n;
  } else if(key > list->tail->key) {
    list->tail->next = n;
    n->prev = list->tail;
    list->tail = n;
  } else {
    node *curr = list->head;
    while(curr->next != NULL && key > curr->next->key) {
      curr = curr->next;
    }
    n->next = curr->next;
    n->prev = curr;
    if(curr->next != NULL) {
      curr->next->prev = n;
    }
    curr->next = n;
  }
}

void pop_head(DLL *list) {
  node *temp = list->head;
  list->head = temp->next;
  temp->next->prev = NULL;
  free(temp);
}

void pop_tail(DLL *list) {
  node *temp = list->tail;
  list->tail = temp->prev;
  temp->prev->next = NULL;
  free(temp);
}

void pop(DLL *list, const int key) {
  if(list->head == NULL) {
    printf("empty list");
    return;
  }
  node *curr = list->head;
  while(curr != NULL && key != curr->key) {
    curr = curr->next;
  }
  if(curr == NULL) {
    printf("not found: %d", key);
    return;
  }
  if(curr == list->head) list->head = curr->next;
  if(curr == list->tail) list->tail = curr->prev;
  if(curr->next != NULL) curr->next->prev = curr->prev;
  if(curr->prev != NULL) curr->prev->next = curr->next;
  free(curr);
}

void display_forward(const DLL *list) {
  const node *curr = list->head;
  while(curr != NULL) {
    printf("%d ", curr->key);
    curr = curr->next;
  }
  printf("\n");
}

void display_backward(const DLL *list) {
  const node *curr = list->tail;
  while(curr != NULL) {
    printf("%d ", curr->key);
    curr = curr->prev;
  }
  printf("\n");
}

int main() {
  DLL *list = newDLL();
  push_asc(list, 2);
  push_asc(list, 9);
  push_asc(list, 7);
  push_asc(list, 1);
  push_asc(list, 10);
  pop(list, 9);
  display_forward(list);
  display_backward(list);
  free(list);
  return 0;
}