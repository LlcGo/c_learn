#include <stdio.h>

typedef unsigned int Index;
typedef struct ListNode * Position;
typedef char * ElementType 
struct ListNode
{
	ELementType element;
    Position * next;	
};

typedef Position List;

struct HashTbl
{
	int tableSize;
	List * theLists;
};

typedef HashTbl * HashTable;


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

void insert(ElementType key, HashTable H)
{
	Position P, newCell;
	List L;
	P = Find(key,H);
	// 没有这个值
	if(P == NULL)
	{
		// 创建新节点
		newCell = (Position)malloc(sizeof(ListNode));
		// 放入值
		newCell->element = key;
		// hash后的数组位置
		L = H->theLists[hash(key,H->tableSize)];
		newCell->next = L->next;
		L->next = newCell;
	}
}
