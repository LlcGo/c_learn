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
