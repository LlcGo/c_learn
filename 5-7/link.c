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

LinkList find(ElementType e, LinkList L)
{
     // 跳过头节点
     LinkList tmp = L->next;
     while(tmp != NULL && tmp->value != e)
     {
        tmp = tmp->next;   
     }
     return tmp;
}

LinkList findPre(ElementType e, LinkList L)
{
    LinkList tmp = L->next;
    while(tmp != NULL && tmp->next->value != e)
    {
       tmp = tmp->next;
    }
    return tmp;
}


void Delete(ElementType e, LinkList L)
{
    
}
