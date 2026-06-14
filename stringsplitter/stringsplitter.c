// a string splitter that spits out tokens from a string
// we should stick with building tokens around the space character

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
   char *string;
   size_t pos;
} str;

char *stringsplit(str *ptr){
   char *tok = NULL;
   size_t i = 0;

   if(isspace(ptr->string[ptr->pos]))
      while(isspace(ptr->string[ptr->pos]))
         ptr->pos++;
   
   while(!isspace(ptr->string[ptr->pos]) && ptr->string[ptr->pos] != '\0'){
      tok = realloc(tok, i + 1);
      tok[i] = ptr->string[ptr->pos];
      ptr->pos++;
      i++;
   }
   tok = realloc(tok, i + 1);
   tok[i] = '\0';

   return tok;
}

int main(void){
   int i = 5, j = 0;
   char c, *tok;
   str line;
   line.string = (char *)malloc(200 * sizeof(char));
   line.pos = 0;
   while(i > 0){
      printf(">");
      while((c = getchar())){
         if(c != '\n'){
            line.string[j] = c;
            j++;
         }
         else
            break;
      }
      line.string[j] = '\0';
      
      tok = stringsplit(&line);
      while(tok[0] != '\0'){
         printf("%s\n", tok);
         free(tok);
         tok = stringsplit(&line);
      }
      free(tok);
      i--;
   }
   free(line.string);
   return 0;
}
