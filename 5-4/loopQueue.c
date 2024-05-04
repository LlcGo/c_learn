#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{   
  ElemType *base //存放内存分配基本地址
  int front;
  int rear;
}

void initQueue(cycleQueue *q)
{
  q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
  q->front = q->rear = 0;
}

void insertQ(cycleQueue * q,ElemType e)
{
  // 队列满了
  if((q->rear+1)%MAXSIZE == q->front)
     return;
  q->base[q->rear] = e;
  q->rear = (q->rear+1) % MAXSIZE;
}

void Delete(cycleQueue * q,ElemType e)
{
  // 队列为空
  if(q->front == q->rear)
     return;
  *e = q->base[q->front];
  q->front = (q->front + 1) % MAXSIZE;
}


