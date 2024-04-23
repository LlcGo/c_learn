#include <stdio.h>

//枚举默认连续 默认从0开始
enum DAY
{
    MON=1,TUE,WED,THU,FRI,SAT,SUM
} day;



int main(void)
{
  // 枚举若需要遍历 需连续
  for(day = MON; day <= SUM; day++)
  {
    printf("枚举元素:%d\n",day);
  } 
  return;
}
