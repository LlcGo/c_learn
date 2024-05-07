#include <stdio.h>
#include <stdlib.h>
#define SpaceSize 100

typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
  ElementType value;
  Position Next;
};


strcut Node CursorSpace[SpaceSize];

static Position CursorAlloc(void)
{
   Position p;
   p = CursorSpace[0].next;
   CursorSpace[0] = CursorSpace[p].next;
   return p;
}

static void  CursorFree(Position P)
{
   CursorSpace[p].next = CursorSpace[0].next;
   CursorSpace[0].next = p;
}

int IsEmpty(List L)
{
   return CursorSpace[L].next == 0;
}

Position Find(ElementType e,List L)
{
  Position p;
  p = CursorSpace[L].next;
  while(p && CursorSpace[p].value != e)
     p = CursorSpace[p].next; 
  return p;
}

Position FindPre(ElementType e,List L)
{
  Position p;
  p = CursorSpace[L].next;
  while(p && CursorSpace[CursorSpace[p].next].value != e)
     p = CursorSpace[p].next;
  return p;
}


void Delete(ElmentType e,List L)
{
   Position p,tmp;
   p = findPre(e,L);
   if(CursprSpace[p].next != 0)
   {
     tmp = CursorSpace[p].next;
     CursorSpace[p].next = CursorSpace[tmp].next;
     free(tmp);
   }
}

void insert(ElementType e,List L,Position p)
{
  Position tmp;
  tmp = CursorAlloc();
  CursorSpace[tmp].value = e;
  CursorSpace[tmp].next = CursorSpace[p].next;
  CursorSpace[p].next = tmp; 
}

