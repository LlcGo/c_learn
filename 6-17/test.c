#include <stdio.h>
#include <stdint.h>


#define SEXT(x, len) ({ struct { int64_t n : len; } __x = { .n = x }; (uint64_t)__x.n; })

int main(){
   int i = 111;
   printf("%#X\n",i);
   SEXT((long long)i,32);  
   printf("%#X\n",i); 
   return 0;
}
