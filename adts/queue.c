#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
} Queue;

void enqueue(Queue* queue, int v) {
    Node* node =  malloc(sizeof(Node));
    node->value = v;
    node->next = NULL;

    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }

    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->front != NULL) {
        Node* temp = queue->front;
        int value = temp->value;
        queue->front = temp->next;
        free(temp);
        queue->size--;
        return value;
    }
    return -1; // or any other appropriate value for an empty queue
}

int size(Queue* queue) {
    return queue->size;
}

int peek(Queue* queue) {
    if (queue->front != NULL) {
        return queue->front->value;
    }
    return -1;
}