#include <stdio.h>
#include <stdlib.h>
#define MAX 32767 //顶点不通 如果自己和自己就是0

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
            if(g->arcs[i][j] > 0 && g->arcs[i][j] != MAX)
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
        if(g->arcs[index][i] > 0 && !visited[i] && g->arcs[index][i] != MAX)
        {
            DFS(g,visited,i);
        }
    }
}

void flody(G g)
{
    int d[g->vexNum][g->vexNum];
    int p[g->vexNum][g->vexNum];
    for(int i = 0; i < g->vexNum; i++)
    {
        for (int j = 0; j < g->vexNum; j++)
        {
            d[i][j] = g->arcs[i][j];
             // 设置p矩阵 如果有弧
            if(g->arcs[i][j] != MAX && g->arcs[i][j] > 0)
            {
                p[i][j] = i;
            }
            else
            {
                p[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < g->vexNum; i++)
    {
        for (int j = 0; j < g->vexNum; j++)
        {
           for (int k = 0; k < g->vexNum; k++)
          {
            if(d[j][k] > d[j][i] + d[i][k])
            {
                d[j][k] = d[j][i] + d[i][k];
                p[j][k] = p[i][k];
            }
          }
        }
    }
    for(int i = 0; i < g->vexNum; i++)
    {
         for (int j = 0; j < g->vexNum; j++)
         {
            printf("%d ",d[i][j]);
         }
          printf("\n");
    }
    printf("\n");
    for(int i = 0; i < g->vexNum; i++)
    {
         for (int j = 0; j < g->vexNum; j++)
         {
            printf("%d ",p[i][j]);
         }
          printf("\n");
    }

}


int main()
{
    G g = initGraph(4);
    int * visited = (int*)malloc(sizeof(int) * g->vexNum);
    for(int i = 0; i < g->vexNum; i++)
    {
        visited[i] = 0;
    }
    int arcs[4][4] = {
        0,1,MAX,3,
        1,0,2,2,
        MAX,2,0,8,
        3,2,8,0
    };
    creatGraph(g,"1234",(int*)arcs);
    DFS(g,visited,0);
    printf("\n");
    flody(g);
    return 0;
}