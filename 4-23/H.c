#include <stdio.h>
// 格式如此
#define message_for(a,b) printf(#a " and " #b": We love you\n")
#define MAX(x,y) (x > y ? x : y)


int main()
{
   message_for(c,java);
   printf("File :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );
   printf("宏定义函数->%d\n",MAX(10,6));
   return 0;
}
