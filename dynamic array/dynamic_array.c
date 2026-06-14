//An implementation of a dynamic array data structure
//error handling standard
// 1 = failure
// 0 = success
// 
#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int *data;
   size_t size;
   size_t capacity;
} dynamicarray;

int da_init(dynamicarray *);
int da_push(dynamicarray *, int);
int da_pop(dynamicarray *, int *);
int da_get(dynamicarray *, size_t, int *);
int da_set(dynamicarray *, size_t, int);
void da_free(dynamicarray *);

int da_init(dynamicarray *arrptr){ //creates array initially
   arrptr->size = 0;
   arrptr->capacity = 4;
   arrptr->data = (int *)malloc(arrptr->capacity * sizeof(int));
   if(arrptr->data == NULL)
      return 1;
   else
      return 0;
   
}

int da_push(dynamicarray *arrptr, int value){  //writes to the end
   if(arrptr->size == arrptr->capacity){
      arrptr->capacity *= 2;
      int *temp;
      temp = (int *)realloc(arrptr->data, arrptr->capacity * sizeof(int));

      if(temp != NULL)
         arrptr->data = temp;
      else
         return 1;
   }

   arrptr->data[arrptr->size] = value;
   arrptr->size++;

   return 0;
}

int da_pop(dynamicarray *arrptr, int *value){  //reads from the end;
   if(arrptr->size > 0){
      *value = arrptr->data[arrptr->size - 1];
      arrptr->size -= 1;
      return 0;
   }

   return 1;
}

int da_get(dynamicarray *arrptr, size_t i, int *value){  //reads a specific index
   if(i < arrptr->size){
      *value = arrptr->data[i];
      return 0;
   }
   return 1;
}

int da_set(dynamicarray *arrptr, size_t i, int value){  // writes to a specific index
   if(i < arrptr->size){
      arrptr->data[i] = value;
      return 0;
   }
   return 1;
}

void da_free(dynamicarray *arrptr){  //empties the array
   arrptr->size = 0;
   arrptr->capacity = 0;
   free(arrptr->data);
   arrptr->data = NULL;
}
