#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
   char *vexs;
   int **arcs;
   int vexNum;
   int arcNum;
}Graph;

Graph* initGraph(int vexNum){
     int i;
     Graph* G = (Graph *)malloc(sizeof(Graph));
     G->vexs = (char*)malloc(sizeof(char) * vexNum);
     G->arcs = (int**)malloc(sizeof(int*) * vexNum);
     for(i = 0; i < vexNum; i++){
	     G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
     }
     G->vexNum = vexNum;
     G->arcNum = 0;
     return G;
}

void DFS(Graph* G,int* visited,int index){
	int i;
	printf("%c\t",G->vexs[index]);
	visited[index] = 1;
	for(i = 0; i < G->vexNum; i++){
		if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX  && !visited[i]){
	              DFS(G,visited,i);
		} 
	}
}

void createGraph(Graph* G,char* vexs, int* arcs){
	int i,j;
	for(i = 0; i < G->vexNum; i++){
            G->vexs[i] = vexs[i];
	    for(j = 0; j < G->vexNum; j++){
		    G->arcs[i][j] = *(arcs + i * G->vexNum + j);
		    if(G->arcs[i][j] != 0 && G->arcs[i][j] != MAX)
			    G->arcNum++;
	    }
	}
	G->arcNum /= 2;
}

int main(){
	int i;
	Graph* G = initGraph(5);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for(int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[5][5] = {
	   0,1,1,1,0,
	   1,0,1,1,1,
	   1,1,0,0,0,
	   1,1,0,0,1,
	   0,1,0,1,0
	};
	createGraph(G,"ABCDE",(int*)arcs);
	DFS(G,visited,0);
}
