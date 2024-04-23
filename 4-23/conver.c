#include<stdio.h>

int main(void)
{
  int num = 17,count = 5;
  double mean;
  // 先转后除
  mean = (double)num / count;
  printf("强转后的mean->%f\n",mean);

  // 整数提升
  char c = 'c';
  printf("c=%d\n",c);
  int cp = c + num;
  printf("num=%d\n",num);
  printf("cp=%d\n",cp);
  return 0;
}
