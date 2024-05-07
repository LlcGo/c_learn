#include <stdio.h>
#include <stdlib.h>
#define ElementType int


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



List * find(ElementType e, LinkList L)
{
     // 跳过头节点
     LinkList tmp = L->next;
     while(L != NULL && tmp->value != value)
     {
        tmp = tmp->next;   
     }
     return tmp;
}
