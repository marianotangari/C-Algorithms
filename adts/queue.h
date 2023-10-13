#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
} Queue;

void enqueue(Queue* queue, int v);
int dequeue(Queue* queue);
int size(Queue* queue);
int peek(Queue* queue);

#endif 