#include <stdio.h>

char * find_char(char const * source, char const * chars);
char * find(const char* str, const char* strCharSet);
int main(void)
{
  char source[6] = "hello";
  printf("值为:%s\n",find(source,"l")); 
  printf("值为:%s\n",find_char(source,"l")); 
  return 0;
}

// 我的方式 会改变原来的指针 不建议这样操作
char * find_char(const char * source,const char * chars)
{ 
  while(*source++ != '\0')
  {
     if(*chars == *source)
     {
         return (char*)source;
         break; 
     }
  } 
  return NULL;    
}


char * find(const char* str, const char* strCharSet)
{
  while (*str)
	{
		const char* pSet = strCharSet;
		while (*pSet)
			if (*pSet++ == *str)
				return (char*)str;
		++str;
	}
	return NULL;
}
