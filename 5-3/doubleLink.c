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

void Caesar(DuLinkList * L,int i);
Status InitList(DuLinkList *L);

Status InitList(DuLinkList *L)
{
   DualNode *p,*q;
   int i;
   *L = (DuLinkList)malloc(sizeof(DualNode));
   (*L)->next = (*L)->prior = NULL;
   p = (*L);
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

void Caesar(DuLinkList * L,int i)
{
    if(i > 0)
    {
      do
      {
         (*L) = (*L)->next;
      }while( --i);
    } 
  
    if( i < 0 )
    {
         (*L) = (*L)->next;
    }while( ++i );
} 

int main()
{
  DuLinkList L;
  int i, n;
  InitList(&L);
  
  printf("请输入一个整数:");
  scanf("%d",&n);
  Caesar(&L,n);
  for(i = 0; i < 26; i++)
  {
    L=L->next;
    printf("%c",L->data);
  }
  
  return 0;
}


