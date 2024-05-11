#include <stdio.h>



void insertionSort(int A[],int N)
{
   int j ,p;
   int tmp;
   for(p = 1; p < N; p++)
   {
       tmp = A[p];
       for(j = p; j> 0 && A[j-1] > tmp; j--)
       {
            A[j] = A[j-1];  
       }
       A[j] = tmp; 
   }

}
