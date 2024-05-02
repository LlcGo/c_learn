#include <stdio.h>
#include <string.h>
void printfx(unsigned  int value);

int main(void)
{
  printfx(12345); 
  return 0;
}


void printfx(unsigned int value)
{
   unsigned  int quotient;
   quotient = value / 10;
   if(quotient != 0)
   {
      printfx(quotient);
   }
   putchar(value % 10 + '0');
}
