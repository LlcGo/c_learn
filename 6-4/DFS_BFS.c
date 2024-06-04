#include <stdio.h>
#include  <stdlib.h>
#include <math.h>
#include <time.h>

typedef int Status;
typedef int Boolean;

typedef char VertextType;
typedef int EdgeType;

#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9

typedef struct
{
   VertextType vexs[MAXVEX]; /*顶点表*/
   EdgeType arc[MAXVEX][MAXVEX]; /*临界矩阵*/
   int numVertexes,numEdges; /*图中当前顶点数和边数*/
}MGRaph;


void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges =15;
	G->numVertexes=9;

	/*建立顶点表*/
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';

	/*初始化图*/
	for(i = 0; i < G->numVertexes;i++)
	{
		for(j = 0; j < G->numVetexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1;
	G->arc[1][8]=1;
	G->arc[1][6]=1;

	G->arc[2][3]=1;
	G->arc[2][8]=1;

	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1;
	G->arc[6][7]=1;

	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
}
