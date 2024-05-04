#include <stdio.h>

#define SIZE 10;

int main(void)
{
  int array[10] = {1,20,33,55,66,77,88,99,101,102};
   int target = 101; 
   int i = search(array,&target);
   printf("%d\n",i);
   return 0;
}


int search(int *  array, int * target)
{
  int end = SIZE;
  int start = 0;
  int mid;
  while(start <= end)
  { 
      mid = (start + end) / 2;
      if((*target) > *(array + mid))
      {
         start = mid + 1;        
      }
      else if( (*target) == *(array + mid))
      {
        break; 
      }
      else
      {
        end = mid - 1;
      }
  } 
  return array[mid]; 
}


