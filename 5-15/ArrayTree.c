#include <stdio.h>

#define MAXSIZE 100 //用数组存储树最多100个单元

typedef int Element; // 树的节点的类型
typedef Element sqTree[MAXSIZE]; //定义一个数组
typedef struct
{
	int level,order; /* 结点的层,本层序号(按满二叉树计算) */
}Position;

// 初始化树
void inintTree(sqTree T)
{
  int i;
  for(i = 0; i < MAXSIZE; i++)
      *(sqTree + i) = 0;
}

// 创建树
void createTree(sqTree T)
{
   int i = 1;
   while(i <= 10)
   {
      *(T + i) = i;
      if(i!=0 && T[i/2] == 0 && T[i] != 0)
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


// 当前树是否为空 如果是空树就返回1 不是就返回0
int isEmpty(sqTree T)
{
  if(T[1] == 0)return 0; 
  return 1;
}

// 返回二叉树深度 2的k次方+1 = 结点 k为深度
int TreeDeep(sqTree T)
{
   int i = 1;
   int count = 0;
   int j = 0;
   while(T[i] != 0)
   {
     count++; //获得当前的二叉树数量
     i++;
   }
   while(count >= powl(2,j)+1)// 计算 2 的几次幂
   {
     j++;
   }
   return --j; 
}

// 返回根节点的值
int  Root(sqTree T, Element *e)
{
  if(!isEmpty(T))
  { 
      *e =  T[1]; 
      return 0;
  }
  *e = -1;
  return -1;
}

// 根据层和序号返回这个二叉树的值
Element Value(sqTree T,Position e)
{
   return T[((int)powl(2,e.level-1)+e.order - 2)];
}


// 给制定位置的二叉树赋新值
int Assign(sqTree T, Position e, Element value)
{
  if(isEmpty(T))
  {
    return -1;
  }
  if(value != 0 && T[i/2] == 0)
  {
    return -1;
  }
  if(value == 0 && (T[2*i]!= 0 || T[2*i+1] !=0)
  {
    return -1;
  }
  T[((int)powl(2,e.level-1)+e.order - 2)] = value;
  return 0; 
}

// 根据value查找双亲
int Parent(sqTree T,Element e)
{
  int i = 1;
  while(T[i]!=e)
  {
     if(T[i] == e)
     {
        return T[i/2];
     }
     i++;
  }
  return -1;
  
}

int leftChild(sqlTree T,Element e)
{
  int i = 1;
  while(T[i]!=e)
  {
     if(T[i] == e)
     {
        return T[2*i];
     }
     i++;
  }
  return -1;
}


int rightChild(sqlTree T,Element e)
{
  int i = 1;
  while(T[i]!=e)
  {
     if(T[i] == e)
     {
        return T[2*i+1];
     }
     i++;
  }
  return -1;
}

int leftSibling(sqlTree T,Element e)
{
  int i = 1;
  while(T[i]!=e)
  {
     if(T[i] == e && i % 2 == 0)
     {
        return T[2*i+1];
     }
     i++;
  }
  return -1;
}

