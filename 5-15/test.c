#include <stdio.h>

int add(int i,int j)
{
  return i+j;
}

int main(void)
{
 int i = 2147483647;
 int j = 2;
 int sum = add(i,j);
 printf("sum = %d\n",sum);
}
