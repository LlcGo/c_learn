#include <stdio.h>

typedef struct Node
{
  int value;
  int height;
  struct Node *lchild, *rchild;
}Node,*AVLTree;


AVLTree newNode(int value)
{
   AVLTree new = (AVLTree)malloc(sizeof(Node));
   new->value = value;
   new->height = 1;
   new->lchild = NULL;
   new->rchild = NULL;
   return new;
}
