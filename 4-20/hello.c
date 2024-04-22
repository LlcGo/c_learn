#include <stdio.h>
int main()
{
  int number;
  printf("请输入字符串");
  scanf("%d",&number);
  int c[number + 1];
  int i;
  for(i = 0; i < number; i++)
  {
     c[i]=i;  
  }
  c[number] = '\0';
  int j;
  for(j=0;j<sizeof(c)/sizeof(c[0]);j++)
  {
    printf("%d\n",c[j]);
  }
  return  0;
}
