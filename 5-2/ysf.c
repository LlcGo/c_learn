#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;

node * create(int n);

int main(void)
{
   int n = 41;
   int m = 3;
   int i;
   node *p =  create(41);
   node * tmp;
   
   m %= n;
   while(p != p->next)
   {
     for(i = 1; i < m-1; i++)
     {
       p=p->next;
     }
     printf("%d->",p->next->data);
     tmp = p->next;
     p->next =tmp->next;
     free(tmp);
     p = p->next;
   }
   printf("%d\n",p->data);
   return 0;
}

node * create(int n)
{
  node *p = NULL, *head;
  head = (node*)malloc(sizeof(node));
  p = head;
  node * new;
  int i = 1;
  while( i< n )
  {
    new =(node*)malloc(sizeof(node));
    new->data = i++;
    p->next = new;
    p = new;
  }
  new->next = head->next;
  free(head);
  return new->next;
} 



