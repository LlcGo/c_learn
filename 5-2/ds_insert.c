#include <stdio.h>

typedef struct node{
  int data;
  struct node * next;
}node;

void ds_insert(node **pNode, int i);

int main(void)
{
  
  return 0;
}

void ds_insert(node **pNode, int i)
{
   node * tmp;
   node * target;
   node * new;
   int item;
   int j = 1;
   printf("输入要插入结点的值");
   scanf("%d",&item);
   if(i == 1)
   {
     // 插入节点为一个位置
     tmp = (node*)malloc(sizeof(node));
     tmp->data  = item;
     for(target = (*pNode); target->next != (*pNode); target = target->next);
     tmp->next = (*pNode);
     target->next = tmp;
     *pNode = tmp; 
   }
   else
   {
     targer = *pNode;
     for(;j<(i-1);++j)
     {
       target = target->next; 
     }
     tmp = (node*)malloc(sizeof(node));
     tmp->data = item;
     tmp->next = target->next;
     target->next = tmp;
         
   }  
}
