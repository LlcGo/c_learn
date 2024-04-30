#include <stdio.h>

int main(void)
{
   int i;
   static int a = 666;
   int *pi = a;
   int **ppi;
   printf("%d\n",ppi);
   //printf("%d\n",&ppi);
   return 0;
}
