#include <stdio.h>

int main(void)
{
  FILE *fp = NULL;
  
  fp = fopen("/tmp/test.text","w+");
  fprintf(fp,"写入测试...\n");
  fputs("test...\n",fp);
  fclose(fp); 
  return 0;
}
