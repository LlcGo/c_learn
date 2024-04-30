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
  
   // 把新值添加到链表
   if(next != NULL)
   {
      //并非链表尾部
      //1.不在起始位置
      if(this != rootp){
        newNode->fwd = next;
        this->fwd = newNode;
        newNode->bwd = this;
        next->bwd = nowNode;
      }else{
      //在起始位置
        newNode->fwd = next;
        rootp->fwd = newNode;
        newNode->bwd = NULL;
        next->bwd = newNode;
      }
   }else{
     // 链表在尾巴
     if(this != rootp){
       //不在头的位置
       newNode->fwd = NULL;
       this->fwd = newNode;
       newNode->bwd = this;
       rootp->bwd = newNode;
     }else{
       // 在头的位置
       newNode->fwd = NULL;
       this->fwd = newNode;
       newNode->bwd = NULL;
       rootp->bwd = newNode;
     }
   }
  return 1;
}
