#include "parser.c"

int main(int argc, char **argv){
   if(argc != 2){
      printf("Invalid number of arguments: Only 1 argument is accepted\n");
      return 1;
   }
   
   FILE *fp = fopen(argv[1], "r");
   if(fp == NULL){
      printf("file could not be opened");
      return 1;
   }

   int err, err2, fieldcnt = 0;
   char *tok;
   array *arrptr = arr_init();
   str line;

   err = get_line(&line, fp);
   while(err != 1 && arrptr->size < arrptr->capacity){
      tok = tokenize(&line);
      while(tok != NULL){
         err2 = row_add(arrptr->rows + arrptr->size, tok);
         if(err2 == 1){
            printf("error adding row\n");
            return 1;
         }
         else{
            printf("add succeeded\n");
            fieldcnt++;
         }
         tok = tokenize(&line);
      }
      arrptr->size++;

      str_free(&line);
      err = get_line(&line, fp);
   }

   printf("%s\n", row_peek(arrptr->rows + 0, 2)); // there is data corruption o sorts within the field storage

   array_free(arrptr);
   free(arrptr);
   fclose(fp);


   return 0;  
}
