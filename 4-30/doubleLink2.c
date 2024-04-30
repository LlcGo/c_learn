#include <stdio.h>

typedef struct NODE{
   struct NODE * fwd;
   struct NODE * bwd;
   int value;
} Node;


int main(void)
{
  return 0;
}

// 双链表插入
int dll_insert(Node * rootp,int value)
{
  // 指向添加新节点之前的位置
  Node * this;
  // 指向新节点添加之后的位置
  Node * next;
  // 新节点
  Node * newNode;
  
  for(this = rootp;(next = this.fwd) != NULL; this = next)
  {
       // 如果这个值已经存在
       if(this->value == value)
            return 0;
       // 找到位置
       if(next->value > value)
         break;
  }
   
   newNode = (Node *) malloc(sizeof(Node *));
   if(nowNode == NULL)
      return -1;
   newNode->value = value;

   newNode->fwd = next;
   this->fwd = newNode;
   if(this != rootp){
        newNode->bwd = this;
   else
        newNode->bwd = NULL;
   if(next != NULL)
        newNode->bwd = newNode;  
   else
        rootp->bwd = newNode; 
  return 1;
}
