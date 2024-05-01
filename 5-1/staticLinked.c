#include <stdio.h>

#define MAXSIZE 1000;

typedef struct {
  int data;
  int cur;
}SlinkList[MAXSIZE];

int InitList(SLinkList space);

int main(void)
{

  return 0;
}


//int InitList(SLinkList space)
//{
//    int i;
//    for(i = 0; i < 4; i++)
//    {
//      spcae[i+1].cur = i+1;
//      space[i+1].data = 'A';  
//    }
//    spcae[0] = 4
//    space[MAXSIZE-1] = 1;
//}

int InitList(Slink spcae)
{
   int i;
   for(i = 0; i < MAXSIZE-1; i++)
   {
       space[i].cur = i+1;
   }
   space[MAXSIZE -1].cur = 0;
   return 0;
}
