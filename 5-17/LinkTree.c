#include <stdio.h>

typedef char Element

typedef struct BiTNode // 结点结构
{
  Element data;
  struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree;


// 初始化树
int initBiTree(BiTree *T)
{
  *T=NULL;
  return 0;
}

// 销毁二叉树
void DestroyBiTree(BiTree *T)
{
   if((*T)->lchild) 
     DestroyBiTree(&(*T)->lchild);
   if((*T)->rchild) 
     DestroyBiTree(&(*T)->rchild);
   if(*T != NULL)
   {
      free(*T);
      *T = NULL 
   }  
}




