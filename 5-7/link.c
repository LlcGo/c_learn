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
  LinkList tmp;
  LinkList pre =  findPre(e,L);  
  if(pre->next != NULL)
  {
     tmp = pre->next; 
     pre->next = tmp->next;
     free(tmp); 
  }  
}

void insert(Element e,List L)
{
   LinkList pre,tmp;
   pre =  findPre(e,L);
   if(pre->next != NULL)
   {
     tmp = (LinList *)malloc(sizeof(Node));
     tmp->value = e;
     tmp->next = pre->next;
     pre->next =tmp;   
   }
}

