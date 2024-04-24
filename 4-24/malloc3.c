#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num;
  int *p = NULL; 
  printf("指针大小:%d\n",sizeof(p));
  printf("请输入需要分配的int大小:");
  scanf("%d",&num);
  p = (int *)malloc(num * sizeof(int));
  printf("指针大小:%d\n",sizeof(p));
  free(p);
  return 0;
}
