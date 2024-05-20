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

int getTreeHeigh(AVLTree T)
{
   if(T == NULL)
     return 0;
   return T->height;
}

int max(int a,int b)
{
  return (a>b)?a:b;
}

// 左旋
AVLTree leftRoat(AVLTree *T)
{
   // 新的根是当前根的右结点
   AVLTree newRoot = T->rchild;
   // 如果当前旋转的新根有左子树，左子树挂到之前根的右子树
   AVLTree newRootLeft = T->lchild;
   // 新的左结点是之前的根
   newRoot->left = T;
   T->rchild = newRootLeft;
   // 更新树高
   newRoot->height = 1 + max(getTreeHeigh(newRoot->lchid),getTreeHeigh(newRoot->rchild));
   T->height = 1 + max(getTreeHeigh(T->lchid),getTreeHeigh(T->rchild));
   return newRoot;
}
// 右旋
