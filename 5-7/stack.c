#include <stdio.h>

#define  ElementType int

struct Node
{
  ElementType Element;
  struct Node *  next;
}

typedef struct Node* stack;

int IsEmpty(stack s)
{
  return s->next == NULL;
}

stack createStack(void)
{
  stack s = (stack)malloc(sizeof(Node));
  s->next = NULL;
  return s; 
}


void push(stack s,ElementType e)
{ 
   stack new = (stack *)malloc(sizeof(Node));
   new->element = e;
   new->next = s->next;
   s->next= new;
}
