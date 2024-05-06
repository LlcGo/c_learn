#include <stdio.h>
#include<stdarg.h>

float average(int n_values,...);

int main(void)
{
  printf("%f\n",average(3,1,2,3));
  return 0; 
}

float average(int n_values,...)
{
   va_list var_arg;
   int count;
   float sum = 0;
   
   // 访问可变参数
   va_start(var_arg,n_values);

   for(count = 0; count < n_values; count++)
   {
      sum += va_arg(var_arg,int);
   }
    
   // 访问结束
   va_end(var_arg);
   return sum / n_values;
}
