#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char name[100];
  char *description
  strcpy(name,"Hello");
  if(description == NULL)
  {
   fprintf(stderr, "Error - unable to allocate required memory\n");
  }
  else 
  {
    strcpy(description, "Zara ali a DPS student.");
  }
  description = (char *)realloc(description,100 * sizeof(char));
  if(description == NULL)
  {
   fprintf(stderr, "Error - unable to allocate required memory\n");
  }
  else 
  {
    strcat(description, "Hai");
  }
  printf("Name = %s\n",name);
  printf("Desc:%s\n",description);
  free(description);
  return 0;
}
