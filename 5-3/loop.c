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

// 创建有环链表
void CreateListTail(LinkList *L , int n)
{
    LinkList new,tmp;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    tmp = *L;
    for(int i; i< n; i++)
    { 
        new = (LinkList)malloc(sizeof(Node));
        new->data = rand()%100 + 1;
        tmp->next = new;
        tmp = new; 
    }
    tmp->next = (*L)->next->next;     
}

int HasLoop1(LinkList L)
{
   LinkList curr1 = L;
   int pos1= 0;
   
   while(curr1)
   {
      LinkList curr2 = L;
      int pos2 = 0;
      while(curr2)
      {
         if(curr2 == curr1)
         {
            if(pos1 == pos2)
                break;
            else
            {
               printf("换的位置在第%d个节点处。\n\n",pos2);
               return OK; 
            }   
         }
         curr2 = curr2->next;
         pos2++;
      } 
     curr1 = curr1->next; 
      pos1++;  
   }   
}

