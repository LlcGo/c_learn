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


