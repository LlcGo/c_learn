#include <stdio.h>
#include <stdlib.h>

void putArray(int x, int y, int (*p)(int,int))
{
  printf("运算结果=%d\n",p(x,y));
  if(p(x,y))
  {
    printf("x>y\n");
  }else{
    printf("y>x\n");
  }
  
}

int getValue(int x,int y)
{
  int i = 0;
  if(x > y)
  {
    i = 1;
  } 
  return i;
}


int getValueRe(int x,int y)
{
  int i = 1;
  if(x > y)
  {
    i = 0;
  }
  return i;
}


int main(void)
{
  int x,y;
  printf("请输入俩个x与y的值");
  scanf("%d %d",&x,&y);
  putArray(x,y,getValueRe);
  return 0;
}
