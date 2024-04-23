#include <stdio.h>

int max(int i,int j)
{
  return i >j ? i : j;
}

int main(void)
{
  int (*p)(int,int) = &max;
  int x,y,d,c;
  printf("请输三个参数\n");
  scanf("%d %d %d",&x,&y,&c);
  d = p(p(x,y),c);
  printf("最大的数值是:%d\n",d);
  return 0;
}
