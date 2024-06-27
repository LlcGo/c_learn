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
        for (size_t j = 0; j < g->vexNum; j++)
        {
           e[index].start = i;
           e[index].end = j;
           e[index].weight = g->arcs[i][j];
           index++;
        }
    }
    return e;
}


/**
 * 当weight为0时候代表添加到集合中
 */
Edge * initEdge(G g,int index){
     Edge * e = (Edge*)malloc(sizeof(Edge) * g->vexNum);
     for (int i = 0; i < g->vexNum; i++)
     {
        e[i].vex = g->vexs[index];
        e[i].weight = g->arcs[index][i];
     }
     return e;
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

void prim(G g,int index)
{
   // 生成第一列矩阵的所有边 将第一条边加入集合
   Edge * e = initEdge(g,0);
   //已经加入一条边少循环一次
   for (size_t i = 0; i < g->vexNum - 1; i++)
   {
        // 获得最小边的索引
        int minIndex = getMinEdge(g,e);
        printf("v%c--->v%c   weight--->%d\n",e[minIndex].vex,g->vexs[minIndex],e[minIndex].weight);
        e[minIndex].weight = 0;
        // 跟新内容
        for (size_t j = 0; j < g->vexNum; j++)
        {
            // 0 6 1 5 MAX MAX  
            // 0 6 0 5 MAX MAX
            // 0 6 0 5 MAX MAX // 1,5,0, 5, 6, 4,
            // 0 5 0 5 6   4
            if(e[j].weight > g->arcs[minIndex][j])
            {
                e[j].weight = g->arcs[minIndex][j];
                e[j].vex = g->vexs[minIndex];
            }
        }
   }
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
    prim(g,0);
    return 0;
}