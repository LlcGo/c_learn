#include <stdio.h>

// 如下方式构建后 不能再用此结构体创建 结构
//struct book
//{
//  char id;
//  char a;
//  int year;
//} book0={"1","2",3};

// 可以利用这个结构体构建多个结构体
struct book
{
  char a;
  char name;
  int id;
} book0;

// 标准
struct book1
{
  char a;
  int id;
  char year;
};

int main(void)
{
  struct book book2;
  struct book1 book1;
  printf("main内部创建sizeof=%d\n",sizeof(book2));
  printf("创建结构体就创建的sizeof=%d\n",sizeof(book0));
  printf("main内部创建sizeof=%d\n",sizeof(book1));
  return 0;
}
