#include <stdio.h>

struct {
  unsigned int a :1;
  unsigned int b :1;
  unsigned int c :1;
  unsigned int d :1;
}prnt;


int main()
{
  prnt.a = 1;
  prnt.b = 0;
  // 因为只能存储一个比特位 所以不能存放 2 = 二进制10超过了 1 个比特位
  prnt.c = 2;
  return 0;
}
