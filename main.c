#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myalloc.h"

int main()
{

// int* a = (int *) myalloc(sizeof(int));
//
// int b = 5;
//
// a = &b;
//
// printf("the integer at memory location %p is %d \n",a, *a);
//
// char* c = (char *) myalloc(sizeof(char));
//
// *c = 'A';
//
// printf("The character at memory location %p is %c\n", c, *c);
//

  char* ptr = (char *)myalloc(6 * sizeof(char));

  printf("The address of the data is %p \n", ptr);

  strcpy(ptr, "AHMAD");

  printf("%s\n", ptr);

  return 0;
}	

