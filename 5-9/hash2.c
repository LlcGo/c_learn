#include <stido.h>
igned int index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

enum KindOfEntry{Legitimate,Empty,Delete};

struct HashEntry
{
	// key
	ElementType Element;
	// 状态
	enum KindOfEntry;
};

typedef struct HashEntry Cell;

struct HashTbl
{
	// 表长
	int TableSize;
	// 元素
	Cell *TheCells;
};

HashTable init(int tableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(HashTbl));
	H->TableSize = tableSize;
	H->TheCells = (HashEntry *)malloc(sizeof(Cell) * H->TableSize);
	for(i = 0; i < H->TableSize; i++)
	{
		H->TheCells[i] == Empty;
	}
	return H;
}
