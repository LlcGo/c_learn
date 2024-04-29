#include <stdio>

typedef struct Node {
     struct Node * next;
     int value;
} Node;

int insert(Node * current, int value);

int main(void)
{
    
   return 0;
}


int insert(Node * current, int value)
{
      Node * node;
      Node * pre;
      Node * new
      node = current;
      while(node->value > value)
      {
        pre = node;
        node = node->next;       
      } 
      new = (Node *)malloc(sizeof(Node *));
      if(new == NULL)
           return 0;
      new->value = value;
      pre->next = new;
      new->next = node;
      return 1;         
}
