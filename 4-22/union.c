#include <stdio.h>
#include <string.h>


union Data{
  int i;
  double f;
  char str[20];
};

int main(void)
{
  union Data data;
  data.i = 6;
  printf("data.i->%d\n",data.i);
  data.f = 6.1;
  printf("data.f->%f\n",data.f);
  strcpy(data.str,"6666");
  // printf("data.i->%d\n",data.i);
  // printf("data.f->%f\n",data.f);
  printf("data.str->%s\n",data.str);
  // printf("sizeof=%d\n",sizeof(data)); 
  return 0;
}
