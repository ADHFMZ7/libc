#include "stdio.h"
#include <string.h>
#include <unistd.h>

int my_puts(const char* str)
{
  ssize_t len = strlen(str);
  return write(1 , str, len);
}

int my_fgets(char* str, int n)
{
  return write(0, str, n);
}



