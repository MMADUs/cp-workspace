#include <stdio.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(const struct Queue *q) {
    return q->front == -1;
}

int isQueueFull(const struct Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void insertQueue(struct Queue *q, const int value) {
    if (isQueueFull(q)) {
        printf("queue is full!\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
}

int popQueue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    const int value = q->items[q->front];
    if (q->front == q->rear) {
        // Last element being removed
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    // init
    struct Queue q;
    initQueue(&q);
    // insert
    insertQueue(&q, 1);
    insertQueue(&q, 2);
    insertQueue(&q, 3);
    // pop
    printf("Dequeued: %d\n", popQueue(&q));
    printf("Dequeued: %d\n", popQueue(&q));
    return 0;
}