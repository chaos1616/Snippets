#include "queue_v2.h"

queue *queue_init(){
   queue *ptr = (queue *)malloc(sizeof(queue));
   if(ptr == NULL)
      return ptr;

   ptr->data = NULL;
   ptr->capacity = 4;
   ptr->size = 0;
   ptr->front = 0;
   ptr->rear = 0;
   ptr->data = (int *)malloc(ptr->capacity * sizeof(int));
   if(ptr->data == NULL){
      free(ptr);
      return NULL;
   }

   return ptr;  
}

int queue_enqueue(queue *ptr, int val){
   if(ptr->size == 0){
      ptr->data[ptr->rear] = val;
      ptr->size++;
      return 0;
   }   
   else if(ptr->size == ptr->capacity){
      queue_resize(ptr);
      ptr->rear++;
      ptr->data[ptr->rear] = val;
      ptr->size++;
      return 0;
   }
   else if(ptr->rear == ptr->capacity - 1 && ptr->front > 0){
      ptr->rear = 0;
      ptr->data[ptr->rear] = val;
      ptr->size++;
      return 0;      
   }
   else{
      ptr->rear++;
      ptr->data[ptr->rear] = val;
      ptr->size++;
      return 0;
   }
   
   return 1;
}

int queue_dequeue(queue *ptr, int *val){
   if(ptr->size == 0)
      return 1;
   else if(ptr->front >= ptr->capacity){
      ptr->front = 0;
      *val = ptr->data[ptr->front];
      ptr->size--;
      
      if(ptr->front < ptr->rear)      
         ptr->front++;
      
      return 0;
   }
   else{
      *val = ptr->data[ptr->front++];
      ptr->size--;
      return 0;
   }
    
   return 1;
}

void queue_resize(queue *ptr){
   const int cap = ptr->capacity;
   ptr->capacity *= 2;
   int *temp = (int *)malloc(ptr->capacity * sizeof(int));

   for(int i = 0, j = ptr->front; i < ptr->size; i++, j++){
      if(j >= cap)
         j = 0;
      temp[i] = ptr->data[j];
   }
   ptr->front = 0;
   ptr->rear = ptr->size - 1;
   free(ptr->data);
   ptr->data = temp;
}

int queue_peek(queue *ptr){
   return ptr->data[ptr->front];
}

int queue_is_empty(queue *ptr){
   if(ptr->size == 0)
      return 1;
   else
      return 0;
}

void *queue_free(queue *ptr){
   free(ptr->data);
   ptr->data = NULL;
   ptr->capacity = 0;
   ptr->size = 0;
   ptr->front = 0;
   ptr->rear = 0;
   free(ptr);

   return NULL;
}
