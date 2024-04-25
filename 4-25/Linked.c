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
       *book = newbook;
        newbook->book = NULL; 
     }else{
       temp = *book;
       *book = newbook;
       newbook->book = temp;    
     }  
      
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

void freeBook(struct Book * book)
{
 
  while(book != NULL)
  {
    free(book);
    book = book->book;
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
   freeBook(book);
  return 0;
}
