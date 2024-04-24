#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char name[100];
  char *description;
  description = (char *)malloc(200 * sizeof(char));
  strcpy(name,"666");
  if( description == NULL)
  {
    fprintf(stderr,"ERROR");
  }
  else
  {
   strcpy(description,"hello");
  }
  printf("Name = %s\n",name);
  printf("Descrip: %s\n",description);
}
