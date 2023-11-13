#ifndef HEAP_H
#define HEAP_H

/*Max heap with fixed size*/
typedef struct Heap {
    int* array;
    int size; 
    int count; 
} Heap; 

Heap init_heap(int size, Heap* heap);
void insert(int value);
int find_max(Heap* heap); 

#endif