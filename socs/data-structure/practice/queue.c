#include <stdio.h>

#define MAX_SIZE 100

struct Queue {
    // stored value
    int items[MAX_SIZE];
    // front index track
    int front;
    // rear index track
    int rear;
};

// init queue (resetting index)
void initQueue(struct Queue *q) {
    q -> front = -1;
    q -> rear = -1;
}

// check if empty
int isQueueEmpty(const struct Queue *q) {
    return q->front == -1;
}

// check if full
int isQueueFull(const struct Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// push value (inserting value in)
void pushQueue(struct Queue *q, const int value) {
    if (isQueueFull(q)) {
        printf("queue is full\n");
        return;
    }
    // if queue is completely empty, init the front
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q -> rear = (q -> rear + 1) % MAX_SIZE;
    q -> items[q -> rear] = value;
}

// pop value (take the value out)
int popQueue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    const int value = q -> items[q -> front];
    if (q -> front == q -> rear) {
        // remove last element
        q -> front = -1;
        q -> rear = -1;
    } else {
        q -> front = (q -> front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    // init
    struct Queue q;
    initQueue(&q);
    // insert
    pushQueue(&q, 1);
    pushQueue(&q, 2);
    pushQueue(&q, 3);
    // pop
    printf("Dequeued: %d\n", popQueue(&q));
    printf("Dequeued: %d\n", popQueue(&q));
    return 0;
}