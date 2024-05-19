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

void DestoryTree(AVLTree T){
      if(T == NULL)
         return;
      deleteTree(T->lchild);
      deleteTree(T->rchild);
      free(T);              
}


AVLTree deleteTree(AVLTree * T,Element e)
{
   if(T == NULL)
   {
     return NULL;
   }
   if((*T)->value > e)
   {
     (*T)->rchild = deleteTree(&(*T)->rchild,e);
     return *T
   }
   else if((*T)->value < e)
   {
     (*T)->lchild = deleteTree((*T)->lchide,e);
     return *T
   }
   else if((*T)->value == e)
   {
       if((*T)->lchild == NULL && (*T)->rchild == NULL)
       {
          free(*T);
          return NULL;        
       }
       if((*T)->lchild != NULL && (*T)->rchild == NULL)
       {
          AVLTree  tmp;
          tmp = (*T)->lchild;
          free(*T); 
          return tmp; 
       }
       if((*T)->lchild == NULL && (*T)->rchild != NULL)
       {
          AVLTree  tmp;
          tmp = (*T)->rchild;
          free(*T);
          return tmp;
       }
       if((*T)->lchid != NULL && (*T)->rchild != NULL)
       {
           AVLTree  cur = (*T)->left;
           while((cur)->rchild != NULL)
           {
             cur = cur->rchild;
           }
          (*cur)->rchild =  (*T)->rchild;
          AVLTree tmp = (*T)->lchild;     
          free(*T);
          return tmp;         
       } 
   }
       
}

