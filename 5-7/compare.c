#include <stdio.h>
#include <string.h>

char pairs(char a)
{
   if(a == '(') return ')';
   if(a == '{') return '}';
   if(a == '[') return ']';
   return 0;
}

int isValid(char * s)
{
   int n = strlen(s);
   if(n % 2 != 0)
   {
      return -1;
   }
   int stk[n],top = 0;
   for(int i = 0; i < n; i++)
   {
     char ch = pair(s);
     if(ch)
     {
        if(top == 0 || stk[top -1] != ch)
        {
                 return -1;
        }  
     }   
     else
     {
       stk[top++] = *(s+i);     
     } 
   }
   return top == 0;  
}
