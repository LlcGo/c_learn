#include <stdio.h>

int jc(int n);

int main(void)
{
   int num;
   printf("请输入数字:\n");
   scanf("%d",&num);
   printf("值--->%d\n",jc(num));
   return 0;
}

int jc(int n)
{
  int result = 1;
  
  while(n > 1)
  {
    result *= n;
    n -= 1;
  }  
 
  return result;
}
