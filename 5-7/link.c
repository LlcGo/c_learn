#include <stdio.h>
#include <stdlib.h>

struct Node 
{
   ElementType value;
   struct Node * next;
}

typedef Node * LinkList;

int isEmpty(LinkList L)
{
  return  L->next == NULL; 
}

