#include <stdio.h>

typedef unsigned int Index;


HashTable init(int tableSize)
{
		HashTable H;
		int i;
		
		// 创建整个HashTable
		H = (HashTable)malloc(sizeof(struct HashTbl));
		H->tableSize = tableSize;
		// 创建HashTable 里面的 链表
		H->theLists = (List)malloc(H->tableSize * sizeof(ListNode));
		for(i = 0; i < H->tableSize; i++)
		{
		    H->theLists[i] =  malloc(sizeof(ListNode));
	    	H->theLists[i]->next = NULL;
		}	
		return H;
}


Index hash(const char *key, int tableSize)
{
   unsigned int hashval = 0;
   while(*key != '\0')
   {
      hashval = (hashval << 5) + *key++;
   }
   return hashval % tableSize;
}

Position Find(ElementType key,HashTable H)
{
	Position P;
	List L;
	// 找到散列到的数组位置
	L = H->theLists[hash(key,H->tableSize)];
	P = L->next;
	while( P != NULL && P->element != key)
	{
		P = P->next;
	}
	return P;
}
