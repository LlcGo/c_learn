#include <stdio.h>

typedef struct node{
  int data;
  struct node * next;
}node;

void ds_delete(node **pNode, int i);

int main(void)
{
  
  return 0;
}

void ds_delete(node **pNode, int i)
{
   node * tmp;
   node * target;
   int j = 1;
   if(i == 1)
   {
     // 如果要删除的是第一个结点
     for(target = (*pNode); target->next != (*pNode); target = target->next);
     tmp = *pNode;
     *pNode =(*pNode)->next;
     target->next = *pNode;
     free(tmp); 
   }
   else
   {
     targer = *pNode;
     for(;j<(i-1);++j)
     {
       target = target->next; 
     }
     tmp = target->next;
     target->next = tmp->next; 
     free(tmp);   
   }  
}
