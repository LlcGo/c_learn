#include <sdtio.h>

void SetUnion(DisjSet S,SetType Root1,SetType Root2)
{
  if(S[Root2] < S[Root1])
  {
     S[Root1] = Root2;
  }
  else
  {
    if(S[Root1] == S[Root2])
    {
       S[Root]--;
    }
    S[Root2] = Root1;
  }
}
