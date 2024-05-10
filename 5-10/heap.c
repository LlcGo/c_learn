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
}
