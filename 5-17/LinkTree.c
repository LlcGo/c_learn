#include <stdio.h>

typedef char Element;
int treeIndex=1;
typedef char String[24];
String str;

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


// 按前序输入二叉树种结点的值
void createBiTree(BiTree *T)
{
    Element ch;
    ch = str[treeIndex++];
    if(ch == '#')
       *T = NULL;
    else
       *T = (BiTree)malloc(sizeof(BiTNode));
       (*T)->data = ch;  
       createBiTree((*T)->lchild);
       createBiTree((*T)->rchild); 
}

// 是否为空树
int BiTreeIsEmpty(BiTree T)
{
   return T == NULL ? 1 : 0;
}

// 返回树的深度
int BiTreeDepth(BiTree T)
{
  int i,j;
  if(T == NULL)
  { 
    return 0;
  }  
  if(T->lchild != NULL)
  {
    i=BiTreeDepth(T->lchild);
  }
  else
  {
    i = 0;
  } 
  if(T->rchild != NULL)
  {
    j=BiTreeDepth(T->rchild);
  }
  else
  {
    j = 0;
  }
  return i > j ? i+1 : j+1;
}

// 返回跟根
Element Root(BiTree T)
{
  if(!BiTreeIsEmpty(T)) return T->data;
  else return 0;
}

void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}

