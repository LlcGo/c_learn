#include <stdio.h>
#include <string.h>

int bf(char * s1,char * s2);

int main(void)
{
  printf("%d\n",bf("abcdef","abc")); 
  printf("%d\n",bf("abcdef","eee")); 
  printf("%d\n",bf("abcdef","bcd"));
  return 0;  
}

int bf(char * s1,char * s2)
{
  int i = 0;
  int j = 0;
  int s1length = strlen(s1);
  int s2length = strlen(s2);
  while(i < s1length && j <s2length)
  {
     if(*(s1+i) == *(s2+j))
     { 
        i++;
        j++;  
     } 
     else
     {
        i = i-j+1;
        j=0;
     }
  }
  if(i >= s1length)
  {
    return -1;
  }
    return i-j;
}
