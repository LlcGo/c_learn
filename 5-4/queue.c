#include <stdio.h>
#include <stdlib.h>

typedef int  ElemType;

typedef struct QNode{
   ElemType data;
   struct QNode *next;
}QNode,*QueuePrt;

typedef struct{
  QueuePrt front,rear; //队头 队尾
}LinkQueue;


void init0(LinkQueue * Q, int n)
{
  int i;
  Q = (QNode *)malloc(sizeof(QNode));
  Q->front = Q;
  LinkQueue Qtmp =  Q;
  LinkQueue new;
  for(i = 0; i < n; i++)
  { 
      mew = (LinkQueue *)malloc(sizeof(LinkQueue));  
      Qtmp->next = new;
      Q->rear = new;
  }   
}

void init1(LinkQueue *q)
{
  q->fornt = q->rear = (QueuePtr)malloc(sizeof(QNode));
  q->front->next = NULL
}

void insert(LinkQueue *q,ElemType e)
{
  QNode new  = (QueuePtr)malloc(sizeof(QNode));
  new->data = e;
  new->next = NULL;
  q->rear->next = new;
  q->rear = new;      
}


void delete1(LinkQueue *q,ElemType *e)
{
   QueuePtr p;
   if(q->front = q->rear)
       return;
   p = q->front->next;
   *e = p->data;
   q->front->next = p->next;
   // 如果是尾部
   if(q->rear == p)
   {
     q->front = q->rear;  
   } 
   free(p);
}

void destory0(LinkQueue *q)
{
   QueuePtr p,q;
   p = q->front->next;
   while(p != q->rear)
   { 
      q = p;
      p=p->next;
      free(q);
   }
   free(q->front);
   free(q->rear);
}

void destory(LinkQueue *q)
{
   while(q->front)
   {
     q->rear = q->front->next;
     free(q->front);
     q->front = q->rear;   
   }
}
