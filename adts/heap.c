#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void init_heap(int size, Heap* heap) {

    heap->array = malloc(sizeof(int) * size); 
    heap->size = size; 
    heap->count = 0; 
}

void insert(int value, Heap* heap) {

    if (heap->count >= heap->size) {

        printf("Error: heap is full. Cannot insert value.\n"); 

    } else if (heap->count == 0) {

        heap->array[0] = value; 

    } else {

        int i = heap->count; 
        int p = (i - 1) / 2;
        
        heap->array[i] = value; 
     
        while(heap->array[p] < value) {

            swap(heap->array, p, i); 

            if(p == 0) {
                break;
            } else {
                i = p; 
                p = (p - 1) / 2; 
            }
        }
    }
    heap->count++; 
}

int find_max(Heap* heap) {
    return heap->array[0]; 
}

 void swap(int* arr, int i, int j) {

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

