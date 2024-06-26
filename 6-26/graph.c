#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    char * vexs; // 顶点
    int ** arcs; // 边（矩阵）
    int vexNum; // 顶点数量
    int arcsNum; // 边的数量
}*G,Graph;

Graph * initGraph(int vexNum)
{
   Graph*  g = (G)malloc(sizeof(Graph));
   g->vexs = (char*)malloc(sizeof(char) * vexNum);
   g->arcs = (int**)malloc(sizeof(int*)*vexNum);
   for (int i = 0; i < vexNum; i++)
   {
       g->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
   }
   g->vexNum = vexNum;
   g->arcsNum = 0;
   return g;
}

void creatGraph(G g, char *vex, int * arcs)
{
    for(int i = 0; i < g->vexNum; i++)
    {
        g->vexs[i] = vex[i];
        for (int j = 0; j < g->vexNum ; j++)
        {
            g->arcs[i][j] = *(arcs + i * g->vexNum + j);
            if(g->arcs[i][j] != 0)
            {
                g->arcsNum++;
            }
        }
    }
    g->arcsNum /= 2;
}

void DFS(G g, int* visited, int index)
{
    printf("%c\t",g->vexs[index]);
    visited[index] = 1;
    for (int i = 0; i < g->arcsNum; i++)
    {
        if(g->arcs[index][i] == 1 && !visited[i])
        {
            DFS(g,visited,i);
        }
    }
}

int main()
{
    G g = initGraph(5);
    int * visited = (int*)malloc(sizeof(int) * g->vexNum);
    for(int i = 0; i < g->vexNum; i++)
    {
        visited[i] = 0;
    }
    int arcs[5][5] = {
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
   creatGraph(g,"ABCDE",(int*)arcs);
    DFS(g,visited,0);
    printf("\n");
    return 0;
}