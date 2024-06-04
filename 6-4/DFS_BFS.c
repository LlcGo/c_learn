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
