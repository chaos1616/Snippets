#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char **fields;
   size_t fieldcount;
   size_t capacity;
} Row;

typedef struct{
   Row *rows;
   size_t capacity;
   size_t size;
} array; // an array of rows with capacity of a 100

typedef struct{
   char *string;
   size_t pos;
} str;

array *arr_init();
void array_free(array *);
int row_add(Row *rp, char *value);
void row_free(Row *rp);
char *tokenize(str *);
int get_line(str *, FILE *);
void str_free(str *sp);
void array_print(array *);
char *row_peek(Row *, size_t);
