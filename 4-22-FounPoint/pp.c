#include <stdio.h>

int main(void)
{
  int number = 666;
  int *p = &number;
  int **pp = &p;
  printf("number=%d\n",number);
  printf("*p=%d\n",*p);
  printf("**pp=%d\n",**pp);
  printf("number=%p\n",number);
  printf("*p=%p\n",*p);
  printf("**pp=%p\n",**pp);
  return 0;
}
