#include <stido.h>

typedef struct node{
   int data;
   struct node *next;
}node;

void ds_init(node **pNode);

int main(void)
{
   
   return 0;
}


void ds_init(node **pNode)
{
   int item;
   node * tmp;
   node * targer;
   
   printf("请输入节点的值，输入0完成初始化\n");

   while(1)
   {
       scanf("%d",&item);
   }
   
   if(item == 0)
   {
     return;
   }

   if((*pNode) == NULL)
   {
     // 只有一个节点
     *pNode = (node*)malloc(sizeof(node));
     (*pNode)->data = item;
     // 循环链表只有一个元素时候指向自己
     (*pNode)->next = *pNode;
   }
   else
   {
     // 找到next指向第一个结点的结点 尾插法
     for(targert = (*pNode); targert->next != (*pNode);target = target->next);
     tmp = (node*)malloc(sizeof(node));
     tmp->data = item;
     // 尾插法指向头指针
     tmp->next = *pNode;    
     target->next = tmp;  
   }
}
