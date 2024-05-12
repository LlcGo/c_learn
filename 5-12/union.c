#include <stdio.h>

#define NumSets 10

typedef int DisJSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;


void init(DsiJSet S)
{
  int i;
  for( i = NumSets; i > 0; i-- )
  {
     s[i] = 0;
  }
}
