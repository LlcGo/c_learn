#include <stido.h>
igned int index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

enum KindOfEntry{Legitimate,Empty,Delete};

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry;
};

typedef struct HashEntry Cell;

struct HashTbl
{
	int TableSize;
	Cell *TheCells;
};
