#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 6);
    enqueue(queue, 8);
    enqueue(queue, 12);
    enqueue(queue, 16);

    printf("%d\n", peek(queue));

    int length = queue_size(queue);

    for (int i = 0; i < length; i++) {
        printf("%d\n", dequeue(queue));
    }

    printf("%d\n", queue_size(queue));

    free(queue);

    return 0;
}