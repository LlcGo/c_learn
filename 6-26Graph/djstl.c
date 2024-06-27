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

int getMin(int *d,int *s,G g)
{
    int min = MAX;
    int index;
    for(int i = 0; i < g->vexNum; i++)
    {
        if(d[i] < min && !s[i])
        {
            min = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(G g,int index)
{
    int * s = (int*)malloc(sizeof(int) * g->vexNum);
    int * p = (int*)malloc(sizeof(int) * g->vexNum);
    int * d = (int*)malloc(sizeof(int) * g->vexNum);
    // s(是否加入集合 加入1)初始化
    for(int i = 0; i < g->vexNum; i++)
    {
        if(index == i)
        {
            s[i] = 1;
        }
        else
        { 
            s[i] = 0;
        }
    }
    // p(当前加入后的新的前驱)初始化
    for(int i = 0; i < g->vexNum; i++)
    {
        if(g->arcs[index][i] > 0 && g->arcs[index][i] != MAX)
             p[i] = 0;
        else
             p[i] = -1;     
    }
    // d（边的权值）初始化
    for(int i = 0; i < g->vexNum; i++)
    {
        if(g->arcs[index][i] > 0 && g->arcs[index][i] != MAX)
             d[i] = g->arcs[index][i];
        else
             d[i] = MAX;     
        if(i == index)
        {
            d[i] = 0;
        }
    }
    for(int i = 0; i < g->vexNum - 1; i++)
    {
        int index = getMin(d,s,g);
        s[index] = 1;
        for(int j = 0; j < g->vexNum; j++)
        {
            // 当这个没有列入最终的集合 并且 当前的距离小于新算出的距离
            if(!s[j] && d[index] + g->arcs[index][j] < d[j])
            {
                d[j] = d[index] + g->arcs[index][j];
                p[j] = index;
            }
        }
    }
    for (size_t i = 0; i < g->vexNum; i++)
    {
        printf("%d %d %d\n",s[i],p[i],d[i]);
    }
    
}

int main()
{
    G g = initGraph(7);
    int * visited = (int*)malloc(sizeof(int) * g->vexNum);
    for(int i = 0; i < g->vexNum; i++)
    {
        visited[i] = 0;
    }
    int arcs[7][7] = {
        0,12,MAX,MAX,MAX,16,14,
        12,0,10,MAX,MAX,7,MAX,
        MAX,10,0,3,5,6,MAX,
        MAX,MAX,3,0,4,MAX,MAX,
        MAX,MAX,5,4,0,2,8,
        16,7,6,MAX,2,0,9,
        14,MAX,MAX,MAX,8,9,0
    };
    creatGraph(g,"1234567",(int*)arcs);
    DFS(g,visited,0);
    printf("\n");
    dijkstra(g,0);
    return 0;
}