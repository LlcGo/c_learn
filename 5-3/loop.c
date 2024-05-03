#include <stdio>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node
{
   ElemType data;
   struct Node *next;
}Node,*LinkList;

Status InitList(LinkList *L)
{
   *L = (LinkList)malloc(sizeof(Node));
   (*L)->next = NULL;
   return OK;  
}

int ListLength(LinkList L)
{
   int i = 0;
   LinkList tmp = L->next;
   while(tmp != NULL)
   {   
       i++;
       tmp = tmp->next;    
   }
   return OK;  
}



