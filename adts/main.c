#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "heap.h"

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 6);
    enqueue(queue, 8);
    enqueue(queue, 12);
    enqueue(queue, 16);

    printf("%d\n", peek(queue));

    int length = size(queue);

    for (int i = 0; i < length; i++) {
        printf("%d\n", dequeue(queue));
    }

    printf("%d\n", size(queue));

    free(queue);

    Heap* heap = malloc(sizeof(heap)); 

    init_heap(16, heap); 

    insert(2, heap); 
    insert(4, heap);
    insert(6, heap); 
    insert(5, heap); 
    insert(1, heap); 
    insert(8, heap); 
    insert(3, heap); 
    insert(7, heap); 
    insert(9, heap); 
    insert(-1, heap); 
    insert(-2, heap); 
    insert(12, heap); 
    insert(12, heap); 
    insert(12, heap); 
    insert(12, heap); 
    insert(12, heap); 
    insert(12, heap); 
    
    printf("%d\n", heap->array[0]);
    printf("%d\n", heap->array[1]);
    printf("%d\n", heap->array[2]);
    printf("%d\n", heap->array[3]);
    printf("%d\n", heap->array[4]);
    printf("%d\n", heap->array[5]);
    printf("%d\n", heap->array[6]);
    printf("%d\n", heap->array[7]);
    printf("%d\n", heap->array[8]);
    printf("%d\n", heap->array[9]);
    printf("%d\n", heap->array[10]);
    printf("%d\n", heap->array[11]);

    printf("%d", find_max(heap)); 
}