#include <stdio.h>
#include <ctype.h>

int main(void){
   int wordcount = 0, linecount = 0, charcount = 0, word_state = 0; //word state dictates if in a word or not
   int c;
   char *file;

   printf(">");
   scanf("%s", file);
   
   FILE *fp = fopen(file, "r");
   if(fp == NULL){
      printf("error opening file");
      return 1;
   }
   
   while((c = fgetc(fp)) != EOF){
      charcount++;
      if(!isspace(c)){
         if((word_state == 0) && isalnum(c)){
            word_state = 1;
            wordcount++;
         }
         else if(!isalnum(c) && word_state != 0){
            word_state = 0;
         }
      }
      else{
         if(word_state  == 1)
            word_state = 0;
         if(c == '\n')
            linecount++;
      }
   }

   fclose(fp);
   
   if(charcount == 0){
      printf("characters : %d\nlines : %d\nwords : %d\n", charcount, linecount, wordcount);
      return 0;
   }

   linecount++;
   printf("characters : %d\nlines : %d\nwords : %d\n", charcount, linecount, wordcount);

   return 0;
}

