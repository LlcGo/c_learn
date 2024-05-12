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


void SetUnion(DisjSet S, SetType Root1,SetType Root2)
{
   S[Root2] = Root1;
}


SetType Find(ElementType x,DisJSet S)
{
   if(S[x] <= 0)
     return x;
   else
     return Find(S[x],S);
}
