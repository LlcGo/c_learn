#include <stdio.h>
#include <stdlib.h>

struct Book{
   char title[20];
   char author[20];
   struct Book * book;
};

void createBook(struct Book *book)
{
  printf("请输入书名:");
  scanf("%s",book->title);
  printf("请输入作者:");
  scanf("%s",book->author);
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
       printf("book为null");
       printf("book之前地址:%p",*book);
       *book = newbook;
       printf("newbook地址:%p",newbook);
       printf("book之后的地址:%p",*book);
       newbook->book = NULL;
     }else{
      printf("新book地址:%p\n",*book);
      temp = *book;
       while(temp->book != NULL){
         temp=temp->book;
       }
       temp->book = newbook;
       newbook->book = NULL;
     }  
      
}

void printfBook(struct Book * book)
{
   struct Book * bk;
   int count = 1;
   bk = book;
   if(bk == NULL)
   {
     printf("打印的bk就是null");
   }
   while(bk != NULL)
   {
     printf("Book%d",count);
     printf("书名:%s,作者:%s\n",bk->title,bk->author);
     bk = bk->book;
     count++;      
   }  
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
  char c;
  while(1){
     printf("是否需要添加书籍(Y/N)");
   do{
      c = getchar();
    }while(c != 'Y' && c != 'N');
    if(c == 'Y')
    {
      printf("%p",book);
      printf("%p",&book);
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
   freeBook(&book);
  return 0;
}
