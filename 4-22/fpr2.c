#include <stdio.h>
#include <stdlib.h>

int add(int x, int y)
{
  return x+y;
}



int (*AFunction(const char * ch, int (*p)(int,int)))(int a,int b)
{
  if(ch == "add")
  {
    return p;
  }
  else
  {
    return NULL;
  } 
}


int main(void)
{
  int(*p)(int,int) = AFunction("add",add);
  int result = p(100,200);
  printf("result--->%d\n",result);
  return 0;
}
