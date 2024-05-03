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

void Magician(linklist head)
{
   linklist p;
   int j;
   int Countnumber = 2;
   p = head;
   p->data = 1;  //放第一张牌

   while(1)
   {
      for(j = 0; j < Countnumber; j++)
      {
          p = p->next;
          if(p->data != 0)
          {
              p->next;
              j--;
          } 
      }
      if(p->data == 0)
      {
          p->data = Countnumber;
          Countnumber++;
          if(Countnumber == 14)
               break;
      }
   }
}
