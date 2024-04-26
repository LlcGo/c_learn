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
   while(current != NULL && current->i < value)
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

void delete(struct Book ** lib,int value)
{ 
    struct Book * current;
    struct Book * pre;
    current = *lib;
    pre = NULL;
    while(current != NULL && current->i != value)
    {
       pre = current;
       current = current->next;
    } 
    if(current == NULL)
    {
       printf("没有找到");
       return;
    }
    else
    {
       if(pre == NULL)
       {
         *lib = current->next;
          return;
       }
       else
       {
         pre->next = current->next;
         return;
       }
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
  int input0;
  int input;
  struct Book * lib = NULL;
  do{
   printf("请输入数字（-1退出）");
   scanf("%d",&input0);
   if(input0 != -1)
     insert(&lib,input0);
   printfBook(lib);
  }while(input0 != -1);
   
  while(1){
    printf("请输入要删除的数字(-1)退出");
    if(input == -1)
      break;
    scanf("%d",&input);
    delete(&lib,input);
    printfBook(lib);
  }
   
  return 0;
}

