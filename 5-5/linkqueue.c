#include "queue.h"
#include <stdio.h>
#include <assert.h>

typedef struct QUEUE_NODE{
   QUEUE_TYPE value;
   struct QUEUE_NODE *next
}QueueNode;

static QueueNode * first;
static QueueNode * rear;

int is_empty(void)
{
  return first == rear;
}


int is_full(void)
{
  return 0; 
}

void delete(void)
{
   QueueNode * next;
   assert(!is_empty())
   next = front->next;
   free(front);
   front = next;
   if(front == NULL)
     rear = NULL;
}

void destory_queue(size_t size)
{ 
   while(!is_empty())
      delete();  
}

void insert(QUEUE_TYPE value)
{
   QueueNode * new;
   new = (QueueNode *)malloc(sizeof(QueueNode));
   new->value = value;
   new->next = NULL;
   if(rear == NULL)
   {
      front = new;
   }
   else
   {
     rear->next = new;
   }
    rear = new;
}

QUEUE_TYPE  first(void)
{
   assert(!is_empty());
   return front->value;
}
