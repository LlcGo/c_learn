#include <stdio.h>

struct HeapStruct
{
  int Capacity;
  int Size;
  ElementType * Elements;
};

typedef struct HeapStruct *ProrityQueue;


