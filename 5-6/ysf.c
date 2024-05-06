#include <stdio.h>
#include <stdlib.h>

int main()
{
  unsigned char val  =  2;
  unsigned char newval = ~val;
  printf("val值->%d\n",val); 
  printf("newval值->%d\n",newval); 
  return 0;
}
