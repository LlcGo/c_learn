#include <stdio.h>

int main()
{
  int arr[] = {1,2,3,4,5};
  char arry[] = "hello";
  // 普通指针
  char *p1 = arry;
  // 指针数组 里面可以存放 2 个 指针
  char *p[2] = {
       "hello",
       "love c"
     };
  // 数组指针 也称为 行指针 ()>[]> * 定义了指向4个元素的一维指针，步长为5
  int (*pp)[5] = &arr;
  int i;
  for(i = 0; i < 2; i++)
  { 
     printf("指针数组遍历:%s\n",p[i]);
  }
  for(i = 0; i < 5; i++)
  {
     // *pp取出地址 + i 解引用；
     printf("数组指针%d\n",*(*pp+i));  
  }
  
  return 0;
}
