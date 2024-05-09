#include <stdio.h>

typedef struct BitNode
{
  ElemType data;
  struct BitNode * lchild, *rchild;
}BitNode,*BitTree;

void createBitTree(BitTree * T)
{
  char c;
  scanf("%c",&c);
  if(' ' == c)
  {
     *T = NULL;
  }
  else
  {
     *T = (BitTree)malloc(sizeof(BitNode));
     (*T)->data = c;
     createBitTree(&(*T)->lchild);
     createBitTree(&(*T)->rchild);
  }
}
