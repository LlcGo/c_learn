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
}
