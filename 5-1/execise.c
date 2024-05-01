#include <stdio.h>
#include <stdlib.h>

typedef struct List{
   int value;
   struct List * next;
}List;


void createLinked(List ** list,int n);
void printfList(List ** list);
void count(List ** list,int * i);
void createLinked(List ** list,int n)
{
   int i;
   List * new;
   List * end;
   // 头节点
   *list = (List *)malloc(sizeof(List));
   end = *list;
   for(i = 0; i < n; i++)
   {
     new = (List *)malloc(sizeof(List));
     new->value = i;
     end->next = new;
     end = new; 
   }
   end->next = NULL;
} 


void printfList(List ** list)
{
   List * tmp;
   tmp = *list;
   while(tmp->next != NULL)
   {
     printf("值->%d\n",tmp->value);
     tmp = tmp->next;    
   }
}

int main(void)
{
   List * list;
   int count1 = 0;
   createLinked(&list,5);
   printfList(&list);
   count(&list,&count1);
   printf("数量->%d\n",count1);
   return 0;
}

void  count(List ** list,int * i)
{
   List * temp;
   temp = *list;
   while(temp->next!=NULL)
   {
      (*i)++;
      temp = temp->next;
   }  
}
