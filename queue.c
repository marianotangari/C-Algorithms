#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    struct Node* list; 
} Queue; 

typedef struct Node {
    int value; 
    struct Node* next; 
    struct Node* prev;
} Node; 

void enqueue(Queue* queue, int v) {
    
    Node* node = (Node*) malloc(sizeof(Node)); 
    node->value = v; 
    
    if (queue->list == NULL) {

        node->prev = NULL; 
        node->next = NULL; 
        queue->list = node; 
        
    } else {
        
        Node* head = queue->list; 
        
        while (queue->list->next != NULL) {
            queue->list = queue->list->next; 
        }
        
        node->prev = queue->list->next; 
        queue->list->next = node; 
        
        queue->list = head; 
    }
}

int dequeue(Queue* queue) {
    
    Node* head = queue->list; 
    
    if (head != NULL) {
        
        int v = queue->list->value; 
        
        if (queue->list->next != NULL) {
            
            Node* next = queue->list->next; 
            queue->list->next->prev = NULL; 
            free(queue->list);
            queue->list = next; 
        } else {
            queue->list = NULL; 
        }
        
        return v; 
    }
    return -1; 
}

int queue_size(Queue* queue) {
    
    if (queue->list == NULL) {
        return 0; 
    } 
    
    Node* head = queue->list;
    
    int i = 1; 
    
    while (queue->list->next != NULL) {
        i++; 
        queue->list = queue->list->next; 
    }
    
    queue->list = head; 
    
    return i; 
}

int peek(Queue* queue) {
     
    if (queue->list == NULL) {
        return -1; 
    }
    
    return queue->list->value; 
}

int main() {
    
    Queue* queue = (Queue*) malloc(sizeof(Queue)); 
    
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
}