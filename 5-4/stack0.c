#include <stdio.h>
#include <stdlib.h>

#define SIZE 10;

typedef int ElemType;

typedef struct
{
  Elemtype * base;
  ElemType * top; 
  int stackSize; 
}Stack;

void init(Stack * s);

void init(Stack * s)
{
    s->base = (ElemType *)malloc(sizeof(ElemType));
    s->top = s->base;
    s->stackSize = SIZE;
}


int main(void)
{

}


int push(Stack * s, int e)
{
  // 俩个数组指针相减，获得此类型个数
  // 如果栈满，追加空间
  if(s->top - s->base >= stackSize)
  {
    // 每次扩容 stackSize个
    s->base = (ElemType *)realloc(s->base,(s->stackSize + SIZE) * sizeof(ElemType)); 
    // top 往上移动 stackSize的空间
    s->top = s->base + s->stackSize;
    // 设置现在的容量
    s->stackSize = s->stackSize + SIZE;
  }
  *(s->top) =  e;
  //上移一位
  s->top++;
  return 0;   
}
