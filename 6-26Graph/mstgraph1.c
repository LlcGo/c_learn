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


//kurskal 边
typedef struct Edge{
    int start;
    int end;
    int weight;
}Edge;

// 初始化边
Edge * initEdge(G g){
    Edge * e = (Edge*)malloc(sizeof(Edge) * g->arcsNum);
    int index = 0;
    for(int i = 0; i < g->vexNum; i++)
    {
        for (size_t j = i + 1; j < g->vexNum; j++)
        {
            if(g->arcs[i][j] != MAX)
            {
                e[index].start = i;
                e[index].end = j;
                e[index].weight = g->arcs[i][j];
                index++;
            }
        }
    }
    return e;
}

void sortEdge(Edge * edge, G g)
{
    Edge tmp;
    for(int i = 0; i < g->arcsNum - 1; i++)
    {
        for(int j = 0; j < g->arcsNum - i - 1; j++)
        {
            if(edge[j].weight > edge[j + 1].weight)
            {
                    tmp = edge[j];
                    edge[j] = edge[j+1];
                    edge[j+1] = tmp;
            }
        }
    }
}


void kruskal(G g)
{
     int *connected = (int*)malloc(sizeof(int) * g->vexNum);
     for(int i = 0; i < g->vexNum; i++)
     {
        // 每一个都是和自己连通的连通分量；
        // 0 1 2 3 4 5 
        connected[i] = i;
     }
     Edge * e = initEdge(g);
     sortEdge(e,g);
     for (size_t i = 0; i < g->arcsNum; i++)
     {
        // e[0].start 边的起点  e[0].end 边的终点 他们的联通分量 
        int start = connected[e[i].start];
        int end = connected[e[i].end];
        //是否不通
        if(start != end)
        {
           printf("v%c--->v%c   weight--->%d\n",g->vexs[e[i].start],g->vexs[e[i].end],e[i].weight);
           // 更新连通分量
           for(int j = 0; j < g->vexNum; j++)
           {
            // 从头到尾遍历 找到 这条边的尾结点 将当前的连通分量变成起始的联通分量
            if(connected[j] == end)
            {
                connected[j] = start;
            }
           }
        }
     }
     
}


int getMinEdge(G g, Edge * e)
{
    int min = MAX;
    int index;
    for (size_t i = 0; i < g->vexNum; i++)
    {
        if(e[i].weight != 0 && min > e[i].weight)
        {
            min = e[i].weight;
            index = i;
        }
    }
    return index;
}



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



int main()
{
    G g = initGraph(6);
    int * visited = (int*)malloc(sizeof(int) * g->vexNum);
    for(int i = 0; i < g->vexNum; i++)
    {
        visited[i] = 0;
    }
    int arcs[6][6] = {
        0,6,1,5,MAX,MAX,
        6,0,5,MAX,3,MAX,
        1,5,0, 5, 6, 4,
        5,MAX,5,0,MAX,2,
        MAX,3,6,MAX,0,6,
        MAX,MAX,4,2,6,0
    };
    creatGraph(g,"123456",(int*)arcs);
    DFS(g,visited,0);
    printf("\n");
    kruskal(g);
    return 0;
}