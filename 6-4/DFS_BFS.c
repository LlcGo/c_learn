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


typedef struct
{
	int data[MAXSIZE];
	int front
	int rear;
}Queue;

Status InitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status QueueEmpty(Queue Q)
{
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

Status EnQueue(Queue *Q,int e)
{
	if((Q->rear+1)%MAXSIZE == Q->front)
	{
		return ERROR;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(Queue *Q,int *e)
{
	if(QueueEmpty(*Q))
	{
		return FALSE;
	}
	*e =  Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
}

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

Boolean visited[MAXVEX]; /*访问标志数组*/

/*深度优先*/
void DFS(MGraph G, int i)
{
  int j;
  visited[i] = TRUE;
  printf("%c",G.vexs[i]);
  for(j = 0; j < G.numVertexes; j++)
	  if(G.arc[i][j] == 1 && !visited[j])
		  DFS(G,j); /*对访问的邻接顶点递归调用*/
}

void DFSTraverse(MGraph G)
{
   int i;
   for(i = 0; i < G.numVertexes; i++)
       visited[i] = FALSE; //初始化都没有访问过;
   for(i = 0; i < G.numVertexes; i++)
	   if(!visited[i])
		   DFS(G,i);
}

/*广度优先遍历*/
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);
        for(i = 0; i < G.numVertexes; i++)
	{
		if(!visited[i])
		{
			visitied[i] = TRUE;
			printf("%c ",G.vexs[i]);
		}
		EnQueue(&Q,i);
		while(!QueueEmpty(Q))
		{
			DeQueue(&Q,&i);
			for(j = 0; j < G.numVertexes; j++)
			{
				if(G.arc[i][j] == 1 && !visited[j])
				{
					visited[j] = TRUE;
					printf("%c ",G.vexs[j]);
					EnQueue(&Q,j);
				}
			}
		}
	}

}
