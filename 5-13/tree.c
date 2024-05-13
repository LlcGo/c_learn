#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode
{
   char data;
   struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void PreOrderTraverse(BiTree T,int level);
void createTree(BiTree *T);

void createTree(BiTree *T)
{
  char c;
  scanf("%c",&c);
  if(' ' == c)
  {
     *T = NULL;
  }
  else
  {
     *T = (BiTree)malloc(sizeof(BiTNode));
     (*T)->data = c;
     createTree(&(*T)->lchild);
     createTree(&(*T)->rchild);
  }
}



void PreOrderTraverse(BiTree T,int level)
{
    printf("%c在第%d层\n",T->data,level);
    PreOrderTraverse(T->lchild,level+1);
    PreOrderTraverse(T->rchild,level+1);
}



int main(void)
{
   BiTree T = NULL;
   createTree(&T);
   PreOrderTraverse(T,1);
   return 0;
}
