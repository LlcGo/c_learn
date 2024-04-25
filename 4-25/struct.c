#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81

struct namect{
  char * fname;
  char * lname;
  int letter;
};

void getinfo(struct namect * pst);
void makeinfo(struct namect * pst);
void showinfo(struct namect * pst);
void cleanup(struct namect * pst);
char * s_gets(char * st,int n);

int main()
{ 
  struct namect person;
  getinfo(&person);  
  makeinfo(&person);  
  showinfo(&person);  
  cleanup(&person);  
  return 0;
}

void getinfo(struct namect * pst)
{
   char temp[SLEN];
   printf("请输入姓");
   s_gets(temp,SLEN);
   // + 1 因为字符串结尾有一个默认的\0
   pst->fname = (char*)malloc(strlen(temp)+1);
   // 赋值
   strcpy(pst->fname,temp);
   printf("请输入名");
   s_gets(temp,SLEN);
   pst->lname = (char * )malloc(strlen(temp)+1);
   strcpy(pst->lname,temp); 
}

void makeinfo(struct namect * pst)
{  
  pst->letter = strlen(pst->fname) + strlen(pst->lname); 
}


void showinfo(struct namect * pst)
{
  printf("姓: %s名: %s,你的名字长度是：%d\n",pst->fname,pst->lname,pst->letter);
}

void cleanup(struct namect * pst)
{
  free(pst->fname);  
  free(pst->lname);  
}

char * s_gets(char * st,int n)
{
  char * ret_val;
  char * find;

  ret_val = fgets(st,n,stdin);
  if(ret_val)
  {
    find = strchr(st,'\n');
    if(find)
       *find = '\0';
    else
       while(getchar() != '\n')
           continue; 
  }
  return ret_val;
}
