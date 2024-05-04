#include <stdio.h>
#include <stdlib.h>

#define SIZE 10;


typedef struct ElemType
{
  Elemtype * base;
  ElemType * top; 
  int stackSize; 
}Stack;

void init(Stack * s)
{
    s->base = (ElemType *)malloc(sizeof(ElemType));
    s->top = s->base;
    s->stackSize = SIZE;
}


