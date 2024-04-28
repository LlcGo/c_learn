#include <stdio.h>


int getValue(char ** string, char input);

int main()
{
   char * a = "hello";
   char * b = "hello2";
   char * c = "hello3";
   char * N = NULL;   
   char *p[4] = {a,b,c,N};
   
   char d[10];
   printf("请输入您要查找的字符串");
   scanf("%s",&d);
   printf("是否找到该值:%d",getValue(p,*d));   
   return 0;
}


int getValue(char ** string, char input)
{
  //当前要查找的字符串
  char * nstring;
 
  while((nstring = *string++) != NULL)
  {
       while(*nstring != '\0')
         if(*nstring++ == input)
            return 1;       
  }
  return 0;  
}



