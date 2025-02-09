#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isStackEmpty(const struct Stack *s) {
    return s->top == -1;
}

int isStackFull(const struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, const int value) {
    if (isStackFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top--];
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
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    return 0;
}