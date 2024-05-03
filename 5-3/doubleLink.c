#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct DualNode
{
  ElemType data;
  struct DualNode *prior;
  struct DualNode *next;
}DualNode,*DuLinkList;

Status InitList(DuLinkList *L)
{
   DualNode *p,*q;
   int i;
   *L = (DuLinkList)malloc(sizeof(DualNode));
   (*L)->next = (*L)->prior = NULL;
   p = (*L)
   for(i = 0; i < 26; i++)
   {
      q = (DuLinkList)malloc(sizeof(DualNode));
      q->data = 'A' + i; 
      q->prior = p;
      q->next = p->next;
      p->next = q;
      p = q;    
   }
   p->next = (*L)->next;
   (*L)->next->prior = p;
   return OK;
}

int main()
{
  
  return 0;
}


