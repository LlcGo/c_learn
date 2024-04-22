#include <stdio.h>
#define SIZE 4
int main(void)
{
  int h,l;
  printf("请输入矩阵有多少列");
  scanf("%d",&h);
  printf("请输入矩阵有多少行");
  scanf("%d",&l);
  int matrix[h][l];
  int i,j;
  for(i=0; i < h; i++)
  {
   for(j=0; j < l; j++)
   {
     matrix[i][j]=j;
   }
  }

  for(i=0; i < h; i++)
  {
   for(j=0; j < l; j++)
   {
     printf("%d",matrix[i][j]);
     if(l==j+1)
      {
       printf("\n");
      }
   }
  }
  return 0;
}

