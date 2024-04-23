#include<stdio.h>

int main(void)
{
  int num = 17,count = 5;
  double mean;
  // 先转后除
  mean = (double)num / count;
  printf("强转后的mean->%f\n",mean);
  return 0;
}
