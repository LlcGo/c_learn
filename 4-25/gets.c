#include <stdio.h>
#include <string.h>
#define SIZE 10

int main()
{
  char c[SIZE];
  printf("请输入数据:\n");
  gets(c);
  printf("put出的参数\n");
  puts(c);
  return 0;
}
