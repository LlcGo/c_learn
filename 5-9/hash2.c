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

Position Find(ElementType key,HashTable H)
{
	Position currentP;
	int collisionNum;
	collisionNum = 0;
	currentPos = hash(key,H->TableSize);
	while(H->TheCells[currentPos].info != Empty && H->TheCells[currentPos].Element != key)
	{
		currentPos += 2 * ++CollisionNum - 1;
		if(currentPost >= H->TableSize)
		{ 
		    currentPost -= H->TableSize;
		}
	}
	return cirrentPost;
}


void insert(ElementType key,HashTable H)
{
	Position P;
	P = Find(key,H);
	if(H->TheCells[P].info != Legitimate)
	{
		H->TheCells[P].info = Legitimate;
		H->TheCells[P].Element = key;
	}
}
