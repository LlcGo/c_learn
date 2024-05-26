#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 30
#define Max 2*N-1

typedef struct{
   double weight;
   char s;
   int parent,lchild,rchild;
}HTNode,HuffmanTree[Max+1];

void Select(HuffmanTree ht,int j,int *m1,int *m2); // 找出森林集合中权值最小的俩个

void CreatHuffmanTree(HuffmanTree ht,int n); // 构建哈夫曼树

void HuffmanCoding(HuffmanTree ht,char **hc,int n); // 哈夫曼编码

void printHuffmancode(HuffmanTree ht,int n,char *pwd);// 先序打印

void HuffmanDecoding(HuffmanTree ht,int *m1,int *m2);// 在生成的哈夫曼编码中查询目标

Select(HuffmanTree ht,int j,int *m1,int *m2)
{
   double min1 = 999999999;
   double min2 = 999999999;
   int j;
   for( j = 1; j <= x; j++)
  {
     if(ht[j].weight < min1 && ht[j].parent == 0)
     { 
         min1 = ht[j].weight;
         *m1 = j; 
     }
  }
  
  int k;
  for( k = 1; k <= x; k++)
  {
     if(ht[k].weight < min2 && k !=*m1 && ht[k].parent == 0)
     {
        min2 = ht[k].weight;
        *m2 = k;
     }
  }
}

