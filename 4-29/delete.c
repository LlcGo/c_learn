#include <stdio.h>

int del_substr(char * str,const char *substr);
int d_substr(char * str,const char *substr);

int main(void)
{
  char str[9] = "123qwe456";
  char substr[9] = "qwe";
  d_substr(str,substr); 
  printf("str=%s\nsubstr=%s\n",str,substr);  
  return 0;
}


int del_substr(char * str,const char *substr)
{
  char * tmp;
  while(*str != '\0')
  {   
     if(*substr == *str)
     {
        //查询到相同的俩个字符串
        tmp = str;
        while(*tmp != '\0')
        {
           //如果不完全相等
           if(*str++ != *substr++)
              return 0;  
        }
        // 如果到还没有到末尾 并且都是完全相同的字符串
        if(*substr != '\0')
        {
             while(*str != '\0')
               *tmp++ = *str++;
             *tmp = '\0';
             return 1;   
        }
         
     }
      str++;
  }
}


int d_substr(char * str,const char *substr)
{
  {
   char *tmp;
   while( *str != '\0' )
   {
      if( *substr == *str )
      {
        tmp = str;
        while( *substr != '\0' )
        {
	   if( *str++ != *substr++ )
             return 0;
	}
        if( *substr == '\0' )
        {
	   while( *str != '\0' )
            *tmp++ = *str++;
	    *tmp = '\0';//此处要加'\0'，把后面的垃圾信息给截掉
            return 1;
        }
      }
    str++;    
   }
  }
}
