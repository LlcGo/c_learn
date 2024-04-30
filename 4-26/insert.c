#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book{
  int i;
  struct Book * next; 
};

void insert(struct Book ** lib,int value)
{
   struct Book * current;
   struct Book * pre;
   struct Book * new;
   current = *lib; 
   pre = NULL;
   while(current != NULL)
   {
      pre = current;
      current = current->next;
   }
      new = (struct Book*) malloc(sizeof(struct Book));
      new->i = value;
      new->next = current;
   if(pre == NULL)
   {
     *lib = new;
   }
   else
   {
      pre->next = new;
   }
}

void printfBook(struct Book *book)
{  
  struct Book * bk;
  bk = book;
  while(bk != NULL)
  {
     printf("%d  ",bk->i);
     bk = bk->next;
  }
  putchar('\n');
}  
int main()
{
  int i;
  struct Book * lib = NULL;
  for(i = 0; i < 5; i++)
  { 
     insert(&lib,i+1);
  } 

  printfBook(lib);
}

