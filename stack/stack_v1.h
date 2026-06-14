// A stack data structure
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   int data;
   struct node *nextptr;
} node;

node *stack_init(int value);
node *stack_push(node *head, int value);
int stack_pop(node **headptr, int *value);
int stack_peek(node *headptr);
int stack_is_empty(node *headptr);
node *stack_free(node *headptr);

node *stack_init(int value){ // this function creates the stack's first node
   node *temp = (node *)malloc(sizeof(node));
   if(temp == NULL)
      return  NULL;
   temp->nextptr = NULL;
   temp->data = value;

   return temp;
}// the function takes in an int value, creates a node instance, stores the int value in the node and points the first node to null and returns
 // a pointer to it.

node *stack_push(node *head, int value){ //this function pushes a value unto the stack
   if(head == NULL){
      return stack_init(value);
   }
   node *temp = (node *)malloc(sizeof(node));
   if(temp != NULL){
      temp->nextptr = head;
      temp->data = value;
      return temp;
   }

   return head;;
}  // I am trying to structure the functions so that they always return the headptr i.e the last in after they are done

int stack_pop(node **headptr, int *value){ // this pops a single value from the stack. it takes in a pointer to a pointer which points to the head
   if((*headptr) == NULL){
      return 1; // returns 1 to indicate failure   
   }

   *value = (*headptr)->data;
   node *temp = *headptr;
   *headptr = (*headptr)->nextptr;
   free(temp); 

   return 0; // 0 to indicate success  
}

int stack_peek(node *headptr){
   return headptr->data;
}// this simply returns the top value in the stack

int stack_is_empty(node *headptr){
   if(headptr == NULL)
      return 1; // for true
   else
      return 0;
}

node *stack_free(node *headptr){
   node *temp;

   while(headptr->nextptr != NULL){
      temp = headptr;
      headptr = headptr->nextptr;
      free(temp);
   }
   free(headptr);

   return NULL;
} // you delete each stack tops until you reach the null pointer

// will need to double check this incase of any potential errors
