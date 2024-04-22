#include <stdio.h>
#include <string.h>

struct{
  unsigned int w;
  unsigned int h;
} status0;

struct{
  unsigned int w : 1;
  unsigned int h : 1;
} status1;

struct Persons{
  int age;
  char name[20];
  char hobby[20];
} person = {18,"小王","c语言"};


struct Book{
  int id;
  char title[20];
  char author[20];
};


void printfS();
void printfBook(struct Book *book);

int main(void)
{
  struct Book book1;
  strcpy(book1.title,"C语言");
  strcpy(book1.author,"我不知道");
  book1.id = 666;
  // printf("这本书叫%s\n这本书的作者%s\n这本书的id是%d\n",book1.title,book1.author,book1.id);
  // printfBook(&book1);
  printfS();
  return 0;
}

void  printfBook(struct Book *book)
{
  printf("书名:%s\n",book->title);
  printf("作者:%s\n",book->author);
  printf("id:%d\n",book->id);
}

void printfS()
{ 
   printf("status0-->sizeof=%d\n",sizeof(status0));
   printf("status1-->sizeof=%d\n",sizeof(status1));
}


