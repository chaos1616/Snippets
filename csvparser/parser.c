#include "parser.h"


array *arr_init(){
   array *ap = (array *)malloc(sizeof(array));
   ap->capacity = 300;
   ap->size = 0;
   ap->rows = (Row *)malloc(ap->capacity * sizeof(Row));

   for(size_t i = 0; i < ap->capacity; i++){
      ap->rows[i].fieldcount = 0;
      ap->rows[i].fields = NULL;
      ap->rows[i].capacity = 0;
   }
   return ap;
}

void array_free(array *arrptr){
   for(int i = 0; i < arrptr->size; i++)
      row_free(&arrptr->rows[i]);
         
   free(arrptr->rows);
   arrptr->rows = NULL;
   arrptr->capacity = 0;
   arrptr->size = 0;
}

int row_add(Row *rp, char *value){
   if(rp->fields == NULL){
      rp->capacity = 10;
      rp->fields = (char **)malloc(rp->capacity * sizeof(char *));
   }
   else if(rp->fieldcount == rp->capacity){
      rp->capacity *= 2;
      char **temp = (char **)realloc(rp->fields, rp->capacity);
      if(temp == NULL)
         return 1;
      else
         rp->fields = temp;
   }

   rp->fields[rp->fieldcount] = value;
   rp->fields++;

   return 0;
}

void row_free(Row *rp){
   for(int i = 0; i < rp->fieldcount; i++){
      free(rp->fields[i]);
      rp->fields[i] = NULL;
   }
   free(rp->fields);
   rp->fields = NULL;
   rp->fieldcount = 0;
   rp->capacity = 0;
}

int get_line(str *input, FILE *fp){
   if(feof(fp))
      return 1;   

   char c;
   size_t size = 300;
   char *buffer = (char *)malloc(size * sizeof(char));
   size_t i = 0;

   for(; (c = fgetc(fp)) != '\n' && c != EOF; i++){
      *(buffer + i) = c;
   }

   *(buffer + i) = '\0';
   buffer = (char *)realloc(buffer, i + 1);

   input->string = buffer;
   return 0;
}

char *tokenize(str *line){
   if(line->string[line->pos] == '\0')
      return NULL;
   else if(line->string[line->pos] == ',')
      line->pos++;

   char *tok = (char *)malloc(40 * sizeof(char));  //each field has to be within a limit of 40 characters to prevent errors
   size_t i = 0;

   for(; (line->string[line->pos] != ',') && (line->string[line->pos] != '\0') ; line->pos++){
      tok[i] = line->string[line->pos];
      i++;
   }
   tok[i] = '\0';
   tok = (char *)realloc(tok, i + 1);

   return tok;
}

void str_free(str *sp){
   free(sp->string);
   sp->pos = 0;
}

void array_print(array *arrptr){
   int i, j;
   for(i = 0; i < arrptr->size; i++){
      printf("Row %d:\n", i + 1);
      for(j = 0; j < arrptr->rows[i].fieldcount; j++){
         printf("   %s\n", row_peek(arrptr->rows + i, j));
      }
   }
}

char *row_peek(Row *rp, size_t i){
   return rp->fields[i];
}
