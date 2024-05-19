#include <stdio.h>

typedef int  Element;

typedef struct AVLNode{
   Element value;
   struct AVLNode * lchild, *rchild;
}AVLNode,*AVLTree;

void createAVLTree(AVLTree * T)
{
  // *T = (AVLTree)malloc(sizeof(AVLNode));
   Element c;
   scanf("%c",&c);
   if(c == '#')
   {
      return;
   }
   else
   {
       *T = (AVLTree)malloc(sizeof(AVLNode));
       (*T)->value = c;
       if((*T)->value > c)
            createAVLTree(&(*T)->rchild);
       if((*T)->value < c)
            createAVLTree(&(*T)->lchild); 
   }
}


void findTree(AVLTree T,Element e)
{
   if(T->value > e)
   {
      findTree(T->rchild,e);
   }
   else if(T->value < e)
   {
      findTree(T->lchide,e)
   }
       
}
