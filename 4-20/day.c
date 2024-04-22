#include <stdio.h>
#define SIZE 4
int main(void)
{
  
  int somedate[SIZE] = {123,124,135,136};
  int i;
  for(i=0;i < SIZE; i++)
  {
     printf("%d\n",*(somedate+i));
  }
  return 0;
}
