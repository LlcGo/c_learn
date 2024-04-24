#include <stdio.h>
#include <stdarg.h>

double average(int num,...)
{
   va_list valist;
   double sum = 0.0;
   int i;
   // 设置可变参数
   va_start(valist,num);
    
   for(i = 0; i < num; i++)
   {
     sum += va_arg(valist,int);
   }

   va_end(valist);
   return sum / num;   
}

int main(void)
{
  printf("Average of 2,3,4,5 = %f\n",average(4,2,3,4,5));
}
