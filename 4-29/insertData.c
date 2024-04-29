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


// 需要传入指向头节点的指针的指针，才可以真正操控头节点 如果只是传入 Node * rootp的,函数内无法访问root这个节点
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

// 最终优化
int goodInstert(Node **linkp,int value)
{
    register Node * current;
    register Node * new;
    
    while((current = *linkp) != NULL && current->value <value)
    {
        linkp = &current->next;        
    }
    new = (Node*)malloc(sizeof(Node*));
    if(new == NULL)
    {
       return 0;
    }
    new->value = value;
    new->link = current;  
    *linkp = new;      
}
