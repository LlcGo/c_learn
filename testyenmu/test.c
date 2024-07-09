#include <stddef.h>
#include <stdint.h>
static void *kalloc(size_t size) {
  static char * pos;
  char * ret;
  // 指针指向堆区起点
  char i = 'a';
  if(!pos) pos = &i;
  // 计算分配多少个字节
  int sz = 1;
  // 分配2的k次方字节
  while(sz < size)
  {
      sz *= 2;
  }
// 16
  while((intptr_t)pos % sz != 0)
  {
      pos++;
  }

  ret = pos;
  pos += sz;


  return pos;
}

int main()
{
	kalloc(1);
	kalloc(2);
	kalloc(100);
	return 0;
}
