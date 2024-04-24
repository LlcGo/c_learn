#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int erron;

int main()
{
  FILE *pf;
  int errnum;
  pf = fopen("unexist.text","rb");
  if(pf == NULL)
  {
    errnum = errno;
    fprintf(stderr,"错误输出:%d\n",errno);
    perror("通过 perror 输出错误");
    fprintf(stderr,"错误：%s\n",strerror(errnum));  
  }
  return 0;
}
