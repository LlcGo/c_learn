#include <stdio.h>


int main(void)
{
  
  char * str = "66666666";
  printf("长度为%d\n",mystrlen(str));
  return 0;
}


int mystrlen(char * string)
{
  int length = 0;
  while (*string++ != '\0')
        length++;

  return length;
}
