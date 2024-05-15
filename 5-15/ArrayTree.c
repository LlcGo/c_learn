#include <stdio.h>

#define MAXSIZE 100 //用数组存储树最多100个单元

typedef int Element; // 树的节点的类型
typedef Element sqTree[MAXSIZE]; //定义一个数组

// 初始化树
void inintTree(sqTree T)
{
  int i;
  for(i = 0; i < MAXSIZE; i++)
      *(sqTree + i) = 0;
}

void createTree(sqTree T)
{
   int i = 1;
   while(i <= 10)
   {
      *(T + i) = i;
      if(i!=0 && T[2/i-1] == 0 && T[i] != 0)
      {
           printf("创建树异常");
           return;
      }
     i++;
   }
  
   while(i < MAXSIZE)
  {
     T[i] = 0;
     i++;
  }
}






