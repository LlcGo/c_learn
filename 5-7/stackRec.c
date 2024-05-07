#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node
{
  int capacity;
  int top;
  ElementType * array;
}

typedef Node*  stack;

stack createStack(int max)
{
  stack s;
  s = malloc(sizeof(Node));
  s->arry = (ElementType *)malloc(max * sizeof(ElementType)); 
  s->capacity = max;
  s->top = -1;
  return s;
}

void disposeStack(stack s)
{
  if(s != NULL)
  {
    free(s->array);
    free(s);
  } 
}

int IsEmpty(stack s)
{
  return s->top == -1;
}

int IsFull(stack s)
{
  return s->top == s-> capacity - 1;
}

void push(stack s,ElementType e)
{
  if(IsFull(s))
   Error("Full stack");
  s->top++;
  s->array[s->top] = e;  
}


ElementType top(stack s)
{
   if(!IsEmpty(s))
     return s->array[s->top];
   Error("Empty stack");
   return 0;
}

void pop(stack s)
{
   if(IsEmpty(s))
     Error("empty stack");
   s->top--;
}

ElementType topAndpop(stack s)
{
  if(!IsEmpty(s))
    return s->array[s->top--];
  Error("empty stack");
  return 0;
}
