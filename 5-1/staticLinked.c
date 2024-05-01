#include <stdio.h>

#define MAXSIZE 1000;

typedef struct {
  int data;
  int cur;
}SlinkList[MAXSIZE];

int InitList(SLinkList space);
int deleteList(SLinkList L, int i);
int ListInsert(SLinkList L, int i, int e);


int main(void)
{

  return 0;
}


//int InitList(SLinkList space)
//{
//    int i;
//    for(i = 0; i < 4; i++)
//    {
//      spcae[i+1].cur = i+1;
//      space[i+1].data = 'A';  
//    }
//    spcae[0] = 4
//    space[MAXSIZE-1] = 1;
//}

// 初始化
int InitList(Slink spcae)
{
   int i;
   for(i = 0; i < MAXSIZE-1; i++)
   {
       space[i].cur = i+1;
   }
   space[MAXSIZE -1].cur = 0;
   return 0;
}

// 获得游标分量
int Malloc_SLL(SLinkList space)
{
  // 获得分量
   int i = space[0].cur;
   if(space[0].cur) 
   {
      // 修改为下一个空的分量
      space[0].cur = space[i].cur;
   }
   return i;
}

// 静态链表插入
int ListInsert(SLinkList L, int i, int e)
{
   int j,k,l;
   if(i < 1 || i > LsitLength(L) + 1)
   {
      return 1;
   }
   // 最后一个元素志向最后一个元素，获取最后一个元素的游标
   k = MAXSIZE - 1;
   j = Malloc_SLL(L);
   if(j)
   {
     L[j].data = e;
     for(l = 1; l <= i-1;l++)
     {
         // 获得最后一个元素的游标,并且移动到需要互换的位置
         k = L[k].cur;
     }
     // 游标互换
     L[j].cur = L[k].cur;
     L[k].cur = j;
     return 0;
   }
   return 1;
}


int deleteList(SLinkList L, int i)
{
  int j,k;
  if(i < 1 || i > LsitLength(L) + 1)
  {
      return 1;
  }
  k = MAXSIZE - 1;
  for(j = 1; j < i-1; j++)
  {
    k = L[k].cur;
  }
  j = L[k].cur;
  L[k].cur = L[j].cur;
  Free_SLL(L,j);
  return 0;
}
