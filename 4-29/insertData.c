#include <stdio>

typedef struct Node {
     struct Node * next;
     int value;
} Node;

int insert(Node ** current, int value);

int main(void)
{
    
   return 0;
}


// 为了方便再插入头节点的时候操作所以使用指向头节点指针的指针
int insert(Node **rootp, int value)
{
      Node * node;
      Node * pre;
      Node * new
      node = *rootp;
      while(node != NULL && node->value < value)
      {
        pre = node;
        node = node->next;       
      } 
      new = (Node *)malloc(sizeof(Node *));
      if(new == NULL)
          return 0;
      // 要插入头节点之前 
      new->value = value;
      new->next = node;
      if(pre == NULL)
      {
       // 头指针 不需要有next直接指向 第一个节点
            *rootp = new;
      }
      else
      {          
      pre->next = new;
      }
      return 1;         
}
