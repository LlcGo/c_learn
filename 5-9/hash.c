#include <stdio.h>

typedef unsigned int Index;

Index hash(const char *key, int tableSize)
{
   unsigned int hashval = 0;
   while(*key != '\0')
   {
      hashval = (hashval << 5) + *key++;
   }
   return hashval % tableSize;
}

