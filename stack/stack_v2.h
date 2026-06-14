// A stack implementation, but using dynamic arrays this time
#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int *data;
   size_t size;
   size_t capacity;
} stack;

int stack_init(stack *S);
int stack_push(stack *S, int value);
int stack_pop(stack *S, int *popval);
int stack_peek(stack *S);
int stack_is_empty(stack *S);
void stack_free(stack *S);

int stack_init(stack *S){
   S->size = 0;
   S->capacity = 4;
   S->data = (int *)malloc(S->capacity * sizeof(int));

   if(S->data == NULL){
      S->size = S->capacity = 0;
      return 1; // failure
   }
   else
      return 0; // success
  
}

int stack_push(stack *S, int value){
   if(S->size == S->capacity){
      S->capacity *= 2;
      int *temp  = (int *)realloc(S->data, S->capacity * sizeof(int));
      if(temp != NULL)
         S->data = temp;
      else
         return 1; // fail
   }

   S->data[S->size] = value;
   S->size++;
   return 0;
}

int stack_pop(stack *S, int *popval){
  if(S->size > 0){
     *popval = S->data[S->size-- - 1];
     return 0;
  }

  return 1; 
}

int stack_peek(stack *S){
   return S->data[S->size - 1];
}

int stack_is_empty(stack *S){
  if(S->size == 0)
     return 1;
  else
     return 0;
}

void stack_free(stack *S){
   S->size = S->capacity = 0;
   free(S->data);
   S->data = NULL;
}
