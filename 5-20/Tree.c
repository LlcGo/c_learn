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


AVLTree findTree(AVLTree T,Element e)
{
   if(T == NULL)
   {
      return NULL;
   }
   if(T->value > e)
   {
      findTree(T->rchild,e);
   }
   else if(T->value < e)
   {
      findTree(T->lchide,e)
   }
   return T;        
}

void deleteTree(AVLTree T){
      if(T == NULL)
         return;
      deleteTree(T->lchild);
      deleteTree(T->rchild);
      free(T);              
}




