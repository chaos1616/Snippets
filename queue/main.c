#include "queue_v2.c"
#include <stdlib.h>
#include <time.h>

int main(void){
   int i, val, count = 1000;
   short err; 
   queue *queueptr = queue_init(); 
   if(queueptr == NULL){
      printf("Queue allocation failed!\n");
      return 1;
   }
   srand(time(NULL));
   
   for(i = 0; i < count; i++){
      err = queue_enqueue(queueptr, rand());
      if(err == 1)
         printf("enqueue failure\n");
   }

   for(i = 0; !(err = queue_dequeue(queueptr, &val)) ; i++){
      if(i % 10 == 0)
         putchar('\n');
      printf("%10d", val);
   }

   queue_free(queueptr);
   queueptr = queue_init();
   
   //test wraparound
   size_t k = 3;
   while(k > 0){
      err = queue_enqueue(queueptr, rand());
      if(err == 1)
         printf("loop did not begin");
      k--;
   }


   for(i = 0; i < 10000; i++){
      err = queue_enqueue(queueptr, rand());
         if(err == 1){
            printf("Enqueue_failure\n");
            return 1;
         }
      err = queue_dequeue(queueptr, &val);
         if(err == 1){
            printf("Dequeue_failure\n%d", i);
            return 1;
         }
   }
   printf("\n\ncapacity = %llu\nsize = %llu\nfront = %llu\nrear = %llu\n\n", queueptr->capacity, queueptr->size, queueptr->front, queueptr->rear);
   
   queue_free(queueptr);
   return 0;
}
