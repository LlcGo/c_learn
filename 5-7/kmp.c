#include <stdio.h>
#include <string.h>

void getNext(char * a,int * next)
{
  int j = 0;
  int len = strlen(a);
  int i;
  for(i = 1; i < len; i++)
  {
     while(j>0 && *(a+j) != *(a+i))
     {
         j = next[j-1];
     }
     if(*(a+j) == *(a+i))
     {
        j++;
     }
     next[i]=j;
  }
}

int kmp(char a[],char b[])
{
    int i;
  int next[6];
  next[0] = 0;
  getNext(b,next);
 // return 1;
  int k = 0;
  int p = 0;
  int a1 = strlen(a);
  int b1 = strlen(b);
  while(k < a1 && p <a1)
  {
     if(0 == p || a[k] == b[p])
     {
        k++;
        p++;
     }
     else
     {
       p = next[p-1];
     }
     if(p >= b1)
     {
       return k-p;
     }
   return -1;
  }
}

int main(void)
{
  printf("%d\n", kmp("aaaaaabbbbbbb","bbbbbb"));
  return 0; 
}
