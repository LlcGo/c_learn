#include <stdio.h>
#include <stdlib.h>

void putArray(int *arr,size_t aSize,int (*p)(void))
{
  size_t i;
  for(i = 0; i < aSize; i++)
  {
     arr[i] = p();
  }
}

int getValue(void)
{
  return rand();
}

int main(void)
{
  int arr[10];
  putArray(arr,10,getValue);
  int i; 
  for(i = 0; i < 10; i++)
  {
     printf("%d\n",*(arr+i));
  } 
  return 0;
}
