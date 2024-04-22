#include <stdio.h>

int count;
extern void lookCount();

int main()
{
  count = 5;
  lookCount();
  return 0;   
}
