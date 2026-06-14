#include <complex>
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
   int data;
   struct node *nextptr;
} node;

typedef struct linkedlist{
   node *headptr;
   node *tailptr;
} linkedlist;

int queue_init(linkedlist *listptr);
void queue_enqueue(linkedlist *listptr, int value);
void queue_dequeue();
void queue_peek();
void queue_is_empty();
void queue_free();

int queue_init(linkedlist *listptr, int value){
   if(listptr->headptr != NULL || listptr->tailptr != NULL)
      return 1; // failure 

   node *temp = (node *)malloc(sizeof(node));
   temp->data = value;
   temp->nextptr = NULL;
   listptr->headptr = listptr->tailptr = temp;
   return 0; 
}

void queue_enqueue(linkedlist *listptr, int value){
   node *temp = (node *)malloc(sizeof(node));
   temp->data = value;
   temp->nextptr = NULL;

   listptr->tailptr->nextptr = temp;
   listptr->tailptr = temp;
}

int queue_dequeue(linkedlist *listptr){
   node *temp = listptr->headptr;
   int value = temp->data;
   listptr->headptr = temp->nextptr;

   free(temp);

   return value;
}

int queue_peek(linkedlist *listptr){
   return listptr->headptr->data; 
}

int queue_is_empty(linkedlist *listptr){
   if(listptr->headptr == NULL && listptr->tailptr == NULL)
      return 1; //true
   else
      return 0; //false  
}

void queue_free(linkedlist *listptr){
   node *nodeptr = listptr->headptr;

   while(nodeptr->nextptr != NULL){
      listptr->headptr = listptr->headptr->nextptr;
      free(nodeptr);
      nodeptr = listptr->headptr;
  }
  free(nodeptr);
  listptr->tailptr = listptr->tailptr->nextptr;
}
