#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int *data;
   size_t front;
   size_t rear;
   size_t size;
   size_t capacity;
} queue;

queue *queue_init();
int queue_queue(queue *ptr, int val);
int queue_dequeue(queue *ptr, int *val);
void queue_resize(queue *ptr);
int queue_peek(queue *ptr);
int queue_is_empty(queue *ptr);
void *queue_free(queue *ptr);  


