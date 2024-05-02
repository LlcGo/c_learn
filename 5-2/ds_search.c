#include <stdio.h>

typedef struct node{
  int data;
  struct node * next;
}node;

void ds_search(node **pNode, int i);

int main(void)
{
  
  return 0;
}

int  ds_search(node **pNode, int i)
{
   node * target;
   target = *pNode;
   int i;
   for(;target->data != i && target->next != *pNode; ++i) 
   {
     target = target->next;
   }
   if(target->next = *pNode)
      return 0;
   else
     return i; 
}
