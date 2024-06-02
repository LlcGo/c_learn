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

void CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgNode *e;
	printf("请输入顶点数和边数:\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges);
	for(i = 0; i < G->numNodes; i++)
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for(k = 0; k < G->numEdges; k++)
	{
		printf("输入边(vi,vj)上的顶点序号:\n");
		scanf("%d,%d",&i,&j);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge=e;
	}
}



