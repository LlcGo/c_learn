#include <stdio.h>

void  printfR();

int main()
{
  printfR();
  return 0;
}

void  printfR()
{
   char a;
   scanf("%c",&a);
   if(a != '#') printfR();
   if(a != '#') printf("%c",a);
}
