#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct node {
  char name[50];
  struct node *next;
  struct node *prev;
} node;

typedef struct hash_table {
  node *thead[ALPHABET_SIZE];
  node *ttail[ALPHABET_SIZE];
} HT;

HT *newHT() {
  HT *table = (HT *)malloc(sizeof(HT));
  for(int i = 0; i < ALPHABET_SIZE; i++) {
    table->thead[i] = NULL;
    table->ttail[i] = NULL;
  }
  return table;
}

node *newNode(const char *name) {
  node *n = (node *)malloc(sizeof(node));
  strcpy(n->name, name);
  n->next = NULL;
  n->prev = NULL;
  return n;
}

int hash(const char *name) {
  if(name[0] >= 'A' && name[0] <= 'Z') {
    return (name[0] - 'A') % ALPHABET_SIZE;
  }
  if(name[0] >= 'a' && name[0] <= 'z') {
    return (name[0] - 'a') % ALPHABET_SIZE;
  }
  return 0;
}

void push(HT *table, const char *name) {
  node *n = newNode(name);
  const int idx = hash(name);
  if(table->thead[idx] == NULL) {
    table->thead[idx] = n;
    table->ttail[idx] = n;
  } else if(strcmp(name, table->thead[idx]->name) < 0) {
    n->next = table->thead[idx];
    table->thead[idx]->prev = n;
    table->thead[idx] = n;
  } else if(strcmp(name, table->ttail[idx]->name) > 0) {
    table->ttail[idx]->next = n;
    n->prev = table->ttail[idx];
    table->ttail[idx] = n;
  } else {
    node *curr = table->thead[idx];
    while(curr->next != NULL && strcmp(name, curr->next->name) > 0) {
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

void pop(HT *table, char *name) {
  const int idx = hash(name);
  if(table->thead[idx] == NULL) {
    printf("empty head");
    return;
  }
  node *curr = table->thead[idx];
  while(curr != NULL && strcmp(name, curr->name) != 0) {
    curr = curr->next;
  }
  if(curr == NULL) {
    printf("not found: %s", name);
    return;
  }
  if(curr == table->thead[idx]) table->thead[idx] = curr->next;
  if(curr == table->ttail[idx]) table->ttail[idx] = curr->prev;
  if(curr->next != NULL) curr->next->prev = curr->prev;
  if(curr->prev != NULL) curr->prev->next = curr->next;
  free(curr);
}

void display(const HT *table) {
  for(int i = 0; i < ALPHABET_SIZE; i++) {
    char idxc = (i < 26) ? ('A' + i) : '#';
    printf("%c: ", idxc);
    node *curr = table->thead[i];
    while(curr != NULL) {
      printf("%s -> ", curr->name);
      curr = curr->next;
    }
    printf("NULL\n");
  }
}

int main() {
  HT *table = newHT();
  push(table, "andrian");
  push(table, "anto");
  push(table, "jeremy");
  push(table, "nicole");
  push(table, "mimi");
  push(table, "memo");
  pop(table, "memo");
  display(table);
  free(table);
  return 0;
}
