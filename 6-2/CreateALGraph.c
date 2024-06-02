#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVEX 100

typedef char VertexType; /*顶点类型*/
typedef int EdgeType; /*边上的权值类型*/

typedef struct EdgNode /*边表结点*/
{
	int adjvex;
	EdgeType info;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertextNode /*顶点表结点*/
{
	VertextType data;
	EdgeNode *firstedge;
}VertextNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes,numEdges; /*图中当前结点数和边数*/
}


