#include <stdio.h>

int fbnq(int n);

int main()
{
   int m;
   printf("请输入计算的数字:\n");
   scanf("%d",&m);
   printf("获得的值->%d\n",fbnq(m));
   return 0;
}

int fbnq(int n)
{
    int pre;
    int result;
    int next;
    pre = result  = 1;
    
    while(n > 2)
    {
       n=n-1;
       next = pre;
       pre = result;
       result = pre + next;        
    }
    return result;
}

