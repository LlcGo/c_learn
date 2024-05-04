#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct StackNode
{
  ElemType data; // 存放数据
  struct StackNode * next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
   LinkStackPrt top; //top指针
   int count; //计算元素
}

int push(LinkStack * s,ElemType e)
{
   LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
   p->data = e;
   p->next = s->top;
   s->top = p;
   s->count++;
   return 0;
}


// 出栈
int pop(LinkStack *s,ElemType *e)
{
  *e = s->top->data;
  LinkStack p;
  p = s->top;
  s->top = s->top->next;
  free(p);
  s->count--;
  return 0;   
}
