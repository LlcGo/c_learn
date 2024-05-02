#include <inclue>

typedef struct Node{
  int value;
  struct Node * link;
}Node;


Node * search(Node * node,int const value);
Node * search_list(Node * node,void const * value, int (*compare)(void const *,void const *));
int compare_ints(void const * a,void const * b);

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


int compare_ints(void const * a,void const * b)
{
    if(*(int *)a == *(int*)b)
    {
         return 0;
    }
    else
    {
        return 1;
    }   
}


Node * search_list(Node * node,void const * value, int (*compare)(void const *,void const *))
{
    while(node != NULL)
    {
        if(compare(node->value,value) == 0)
             break;
        node = node->next; 
    }
    return node;
}
