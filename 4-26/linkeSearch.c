#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
   char title[20];
   char author[20];
   struct Book * book;
};

static struct  Book * tail;

void createBook(struct Book *book)
{
  printf("请输入书名:");
  scanf("%s",book->title);
  printf("请输入作者:");
  scanf("%s",book->author);
} 

struct Book * searchB(struct Book *book,char * target)
{
  printf("target=%s",target);
  struct Book *bk = NULL;
  bk = book;
  while (bk != NULL)
  { 
    if(!strcmp(bk->title,target) || !strcmp(bk->author,target))
    {
      break;  
    }
    bk = bk->book; 
  }
  return bk;
}

void add(struct Book **book)
{
    struct Book * newbook,*temp;
    newbook = (struct Book *)malloc(sizeof(struct Book));
    if(newbook == NULL)
    {
      printf("内存空间不足");
      exit(1);
    }
    
    createBook(newbook);
    if(*book == NULL)
    {
       *book = newbook;
        newbook->book = NULL; 
     }else{
       tail->book = newbook;
       newbook->book = NULL;
     }  
    tail = newbook; 
      
}

void printfBook(struct Book * book)
{
   struct Book * bk;
   int count = 1;
   bk = book;
   while(bk != NULL)
   {
     printf("Book%d",count);
     printf("书名:%s,作者:%s\n",bk->title,bk->author);
     bk = bk->book;
     count++;      
   }  
}

void printfB(struct Book * book)
{
  printf("书名：%s,作者：%s",book->title,book->author);
}

void freeBook(struct Book ** book)
{
  struct Book *temp;
  while(*book != NULL)
  {
    temp = *book;
    *book = (*book)->book;
    free(temp);
  }    
}

int main()
{
  struct Book * book = NULL;
  struct Book * search = NULL; 
  char c;
  char bk[10];
  
  while(1){
     printf("是否需要添加书籍(Y/N)");
   do{
      c = getchar();
    }while(c != 'Y' && c != 'N');
    if(c == 'Y')
    {
      add(&book);
    } else{
      break;
    }
  }
    printf("是否需要打印数据(Y/N)");
   do{
     c = getchar();
    }while(c != 'Y' && c != 'N');
    if(c == 'Y'){
     printfBook(book);
    }
   printf("请输入您要查询的书或者作者");
   scanf("%s",&bk);
   search = searchB(book,bk);
   printf("书名");  
   printfB(search);    
   freeBook(&book);
  return 0;
}
