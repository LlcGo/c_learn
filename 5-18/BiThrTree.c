#include <stdio.h>


typedef char Element;
typedef enum {Link,Thread} PointerTage; //标志是线索还是结点
Element Nil= '#';

typedef struct BiThrNode
{
   Element data;
   struct BiThrNode * lchild,*rchild;
   PointerTage LTag;
   PointerTage RTag;  
}BiThrNode,*BiThrTree;

// 构建线索二叉树标志结点
int createBiThrTree(BiThrTree *T)
{
     Element h;
     scanf("%c",&h);
     if(h == Nil)
        *T = NULL;
     else
     {
         *T = (BiThrTree)malloc(sizeof(BiThrNode));
         (*T)->data = h;
         createBiThrTree(&(*T)->lchild);
         if((*T)->lchild)
               (*T)->LTag = Link; 
         createBiThrTree(&(*T)->rchild);
         if((*T)->rchild)
               (*T)->RTag = Link;
     }
   return 0;            
}

//带头节点的线索二叉树
int InOrderThreading(BiThrTree *Thrt,BiThTree T)
{
    *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
    (*Thrt)->LTag=Link; //头节点
    (*Thrt)->RTag=Thread;
    (*Thrt)->rchild=(*Thrt);// 初始指自己
    if(T==NULL)
         (*Thrt)->lchid=*Thrt; //空树指自己
    else
    {
      (*Thrt)->lchild=T;
      pre = (*Thrt);
      InOrderThreading(T);// 中序遍历进行中序线索化
      pre->rchild=*Thrt;
      pre->RTag=Thread;
      (*Thrt)->rchild=pre;
    } 
    return 0;
}

// 中序遍历二叉树设置线索二叉树前驱
BiThrTree pre;
void InThreading(BiThTree p)
{
  if(p)
  {
     InThreading(p->lchild);
     if(!p->lchild)
     {
        p->LTag = Thread;
        p->lchid = pre; 
     }
     if(!pre->rchild)
     {
       pre->rchild = p;
       pre->RTag = Thread; 
     }
     pre = p;
     InThreading(p->rchild);
  }      
}



// 非递归遍历线索二叉树
int InOrderTraverse_Thr(BiThrTree T)
{
   BiThrTree p;
   p = T->lchild;
   while(p!=T)
   {
      while(p->LTag == Link)
      {
          p=p->lchild;
      }
      printf("%c\n",p->data);
      while(p->RTag == Thread&&p->rchild!=T)
      {
         p=p->rchild;
         printf("%c\n",p->data);
      }
      p=p->rchild;
   }
  return 0;
}
