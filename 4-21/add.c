#include <stdio.h>
#define SIZE 4
int main(void)
{
  int arr[] = {1,2,3,4,5};
  int c = add(arr,sizeof(arr)/sizeof(arr[0]));
  printf("%d\n",c);
  return 0;
}

int add(int *a,int n)
{
  int i;
  int c = 0;
  for(i = 0;i < n; i++)
  {
    c += a[i]; 
  }
  return c;
}
