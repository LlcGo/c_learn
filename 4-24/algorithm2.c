#include <stdio.h>

int fb(int i)
{
  if(i == 0)
  {
    return 0;
  }
  if(i == 1)
  {
    return 1;
  }
  return fb(i-1) + fb(i-2);
}

int main(void)
{
  int i,j=10;
  for(i = 0; i < j; i++)
    printf("%d\n",fb(i));  
  return 0;
}
