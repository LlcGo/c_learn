#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film{
  char title[TSIZE];
  int rating;
  struct film * next;  
};

char * s_gets(char * st, int n);

int main(void)
{
  // 头指针
  struct film * head = NULL;
  // 前一个指针 和 当前的指针
  struct film * pre;
  struct film * current;
  // 输入的参数
  char input[TSIZE];
  /* 收集并存储信息 */
  puts("请输入电影名:");
  while(s_gets(input,TSIZE) != NULL && input[0] != '\0')
  {
     current = (struct film *)malloc(sizeof(struct film));
     if(head == NULL)
     {
         head = current;
     }else{
         pre->next = current;
     }
     current->next = NULL;
     strcpy(current->title,input);
     puts("请输入您的评分");
     scanf("%d",&current->rating);
     while (getchar() != '\n')
       continue;
     puts("请输入下一部电影的名称");
     pre = current;
  }
  
  if(head == NULL)
  {
    printf("无数据");
  }else{
    printf("电影值为:\n");
  } 
  current = head;
  while(current != NULL)
  {
    printf("电影名:%s,分数:%d",current->title,current->rating);
    current = current->next;
  }
  /*释放内存*/
  current = head;
  while(current != NULL)
  {
    current = head;
    head=current->next;
    free(current);
  }  
  return 0;
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

