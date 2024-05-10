#include <stdio.h>
#define MinData -1

typedef int ElementType;

struct HeapStruct
{
  int Capacity;
  int Size;
  ElementType * Elements;
};

typedef struct HeapStruct *ProrityQueue;

ProrityQueue init(int MaxElement)
{
  ProrityQueue H;
  H = (ProrityQyeye)malloc(sizeof(struct HeapStruct)); 
  H->Elements = (ElementType *)malloc((MaxElement+1) * sizeof(ElementType)); 
  H->capacity = MaxElement;
  H->Size = 0; 
  H->Elements[1] = MinData;
  return H;
}


void insert(ElementType X,PriorityQueue H)
{
  int i;
  for(i = ++H->Size; H->Elements[i/2] > X; i/=2)
  {
     H->Elements[i] = H->Elements[i/2];
  }
  H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{
  int i,child;
  ElementType MinElement,LastElement;
  MinElement = H->Elements[1];
  LastElement = H->Elements[H->size--];
  for(i = 1; i * 2 <= H->Size; i = child)
  {
    child = i * 2;
    if(child != H->Size && H->Elements[child + 1] < H->Elements[child])
    {
        child++;
    }
    if( LastElement > H->Elements[child])
    {
       H->Elements[i] = H->Elements[child];
    }  
  }
  H->Elements[i] = LastElement;
  return MinElement;
}
