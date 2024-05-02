#include <stdio.h>

typedef struct node{
  int data;
  struct node *next;
}node;

node * create(int n);

int main(void)
{
  create(41);
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


