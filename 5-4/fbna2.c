#include <stdio.h>

int Fib(int i);


int main(void)
{
  printf(("z->%d\n"), Fib(5));   
  return 0;
}

int Fib(int i)
{
  if(i<2)
     return i == 0 ? 0 : 1;
  return Fib(i-1) + Fib(i-2);
} 
