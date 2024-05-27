#include <stdio.h>
// 将 n个 盘子从x 借助y 移动到z
void move(int n,char x,char y,char z)
{
    if(1 == n)
    {
       printf("%c--->%c\n",x,z);
    }
    else
    { 
      // n-1个盘子从x 借助 z 移动到 y
       move(n-1,x,z,y);
       printf("%c--->%c\n",x,z);
      // n-1个盘子从y 借助x 移动到 z
       move(n-1,y,x,z);
    }

}


int main()
{
  int n;
  printf("请输入汉诺塔的层数");
  scanf("%d",&n);
  printf("移动步骤如下:\n");
  move(n,'x','y','z');
  return 0;
}
