#include <stdio.h>
#include <stdlib.h>
#include "list.h" /*定义list Item*/

void showmovies(Item item);
char * s_gets(char * st, int n);

int main(void)
{
  List movies;
  Item temp;
  
  /*初始化*/
  InitList(&movies);
  if(ListIsFull(&movies))
  {
    fprintf(stderr,"没有内存了");
  }
  
  /*获取用户输入并存储*/
  puts("请输入电影");
  while (s_gets(temp.title,TSIZE) != NULL && temp.title[0] != '\0')
  {
    puts("请输入评分<0-10>");
    scanf("%d",&temp.rating);
    while (getchar() != '\n')
      continue;
    if (AddItem(temp,&movies) == false)
    {
       fprintf(stderr,"没有内存了");
       break;
    } 
    if(ListIsFull(&movies))
    {
       puts("List满了");
       break;
    }
    puts("请输入下一个影片（空行退出）");
  } 
  
  /*显示*/
  if (ListIsEmpty(&movies))
     printf("NO Data");
  else
  {
     printf("所有影视:\n");
     Traverse(&movies,showmovies);
  }
  printf("您一共输入了%d电影\n",ListItemCount(&movies));
  
  /*清理内存*/
  FreeList(&movies);
  printf("Bye!\n");
  return 0; 
}

void showmovies(Item item)
{ 
  printf("电影: %s 评分: %d",item.title,item.rating);
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
  ret_val = fgets(st,n,stdin);
  if(ret_val)
  {
     find = strchr(st,'\n');
     if(find)
        *find = '\0';  //构建c语言字符串;
     else
       while(getchar() != '\n')
           continue;            //不等于回车就继续读取  
  }
  return ret_val;
}

