#include <stdio.h>

#define CardNumber 13

typedef struct node
{
   int data;
   struct node * next;
}sqlist,*linklist;


void DestoryList(linklist * list)
{
   linklist ptr = * list;
   linklist buff[CardNumber];
   int i = 0;
   while(i < CardNumber)
   {
        buff[i++] = ptr;
        ptr = ptr->next;
   }
  
   for(i = 0; i < CardNumber; ++i)
       free(buff[i]);
   *list = 0;
}
