#include <stdio.h>
#define MAXVEX 100  /*矩阵多大*/
#define GRAPH_INFINITY 65535 /*无穷大*/

typedef char VertexType; /*边类型*/
typedef int EdgeType;  /*矩阵权值类型*/

typedef struct
{
   VertexType vexs[MAXVEX];
   EdgeType arc[MAXVEX][MAXVEX];
   int numNodes,numEdges;
}MGraph;


void CreateMGraph(MGraph *G)
{
   int i,j,k,w;
   printf("请输入顶点数和边数:\n");
   scanf("%d,%d",&G->numNodes,&G->numEdges);
   for(i = 0; i < G->numNodes; i++) // 初始化顶点表
	   scanf(&G->vexs[i]);
   for(i = 0;i< G->numNodes;i++)
	   for(j = 0; j < G->numNodes;j++)
		   G->arc[i][j] = GRAPH_INFINITY; /*初始化矩阵*/
   for(k = 0; k < G->numNodes; k++)
   {
	   printf("请输入(vi vj)上的下表i, 下标j和权w:\n");
	   scanf("%d,%d,%d",&i,&j,&w);
	   G->arc[i][j] = w;
	   G->arc[j][i] = G->arc[i][j]; /*无向图矩阵对称*/
   }
}

