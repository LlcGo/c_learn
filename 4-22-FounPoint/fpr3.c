#include <stdio.h>
#include <stdlib.h>

// *FUNC = *AFunction(const char * ch, int (*p)(int,int)) = int(*p)(int,int)  
typedef int(*FUNC)(int,int);

int add(int x, int y)
{
  return x+y;
}

//int (*AFunction(const char * ch, int (*p)(int,int)))(int a,int b)
FUNC AFunction(const char * ch,int (*p)(int,int)) 
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
  FUNC p = AFunction("add",add);
  int result = p(100,200);
  printf("result--->%d\n",result);
  return 0;
}
