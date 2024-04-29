#include <stdio.h>

void reverse(char* string);

int main(void)
{
  char string[5] = "12345";
  reverse(string);
  printf("%s\n",string);
  return 0;
}

void reverse(char* string)
{
   char * tail = string;
   while(*tail != '\0')
   {
      // 移动到尾部
      tail++;    
   }
   tail--;
   // 头和尾互换
   while(tail > string)
   {
     char  tmp;
     tmp = *string;
     *string = *tail;
     *tail = tmp; 
     tail--;
     string++;
   }
}

