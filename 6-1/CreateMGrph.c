#include <stdio.h>
#define MAXVEX 100  /**/
#define GRAPH_INFINITY 65535 

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
   VertexType vexs[MAXVEX];
   EdgeType arc[MAXVEX][MAXVEX];
   int numNodes,numEdges;
}MGraph;


