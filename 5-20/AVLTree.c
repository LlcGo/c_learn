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
AVLTree leftRoat(AVLTree T)
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
AVLTree rightRoat(AVLTree T)
{
   // 新的根是原来根的左子树
   AVLTree newRoot = T->lchid;
   // 保存新头结点的右子树
   AVLTree newRootRight =  newRoot->rchild;
   // 原本的根变成的新根的右子树
   newRoot->rchild = T;
   // 新根的右子树的左子树是之前新结点的左子树
   T->lchid = newRootRight;
   // 更新树高
   newRoot->height = 1 + max(getTreeHeigh(newRoot->lchid),getTreeHeigh(newRoot->rchild));
   T->height = 1 + max(getTreeHeigh(T->lchid),getTreeHeigh(T->rchild));
   return newRoot;
}

int getBalance(AVLTree T)
{
   return getHeigh(T->lchid) - getHeigh(T->rchild);
}

AVLTree insertNode(AVLTree T,int key)
{
  if(T == NULL)
  {
     return newNode(key);
  }  
  if(key > T->data)
  {
   T->rchild =  insertNode(T->rchid,key);
  }else if(key < T->data)
  {
   T->lchild =  insertNode(T->lchild,key);
  }else //值已经存在
  {
    return T;
  }
  
  T->height = max(getTreeHeigh(T->lchild),getTreeHeigh(T->rchild));
  
  int balance = getBalance(T);
  // LL
  if(balance > 1 && getBlance(T->lchild) > 0)
    return rightRoat(T);
  // LR 
  if(balance > 1 && getBlance(T->lchild) < 0)
  {
    T->lchild = leftRoat(T->lchid);
    return rightRoat(T);
  }
  // RR
  if(blance < -1 && getBlance(R->rchild) < 0)
     return leftRoat(T);
  // RL
  if(blance < -1 && getBlance(R->rchild) > 0)
  {
    T->rchild = rightRoat(T->rchild);
    return leftRoat(T);
  }
}

// 线序遍历
void preOrder(AVLTree T)
{
   if(T == NULL)
     return NULL;
   printf("%d\n",T->data);
   preOrder(T->lchid);
   preOrder(T->rchild);
}

// 中序遍历
void midOrder(AVLTree T)
{
  if(T == NULL)
     return NULL;
  midOrder(T->lchid);
  printf("%d\n",T->data);
  midOrder(T->rchild;)
}

// 查找结点 并且返回结点数量
AVLTree find(AVLTree T,int key,int *counter)
{
  AVLTree cur = T;
  while(cur != NULL)
  {
     if(key > cur->data)
     {
        cur = cur->rchild;
        *counter++;
     }
     if(key < cur->data)
     {
        cur = cur->lchid;
        *counter++;
     }else
        return cur;
  }
  // 没有找到
  return NULL;
}



