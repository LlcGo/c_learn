#include <inclue>

typedef struct Node{
  int value;
  struct Node * link;
}Node;


Node * search(Node * node,int const value);


int main(void)
{
  return 0;
}

Node * search(Node * node,int const value)
{
  // 防止空链表
   while(node != NULL)
   {
        if(node->value == value)
             break;
        node =node->link;
   }
   return node;
}
