#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    // the stored value
    int items[MAX_SIZE];
    // keep the track of index
    int index;
};

// init stack (resetting index)
void initStack(struct Stack *s) {
    s -> index = -1;
}

// check if empty
int isStackEmpty(const struct Stack *s) {
    return s -> index == -1;
}

// check if full
int isStackFull(const struct Stack *s) {
    return s -> index == MAX_SIZE - 1;
}

// push value (insert the value in)
void push(struct Stack *s, const int value) {
    if (isStackFull(s)) {
        printf("stack is full\n");
        return;
    }
    // insert
    s -> index++;
    s -> items[s -> index] = value;
}

// pop value (take the value out)
int pop(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("stack is empty\n");
        return -1;
    }
    // return out
    s -> index--;
    return s->items[s -> index];
}

int main() {
    // init stack
    struct Stack s;
    initStack(&s);
    // push to stack
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    // pop stack
    printf("popped: %d\n", pop(&s));
    printf("popped: %d\n", pop(&s));
    return 0;
}