#include <stdio.h>

LinkList Connect(ListList A,ListList B)
{
   List tmp = A->rear;
   A->next = B->next->next;
   free(B->next);
   B->next = tmp;
   return B;
}
