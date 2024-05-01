#include <stdio.h>
#include <stdlib.h>

typedef struct List{
   int value;
   struct List * next;
}List;


void createLinked(List ** list,int n);
void printfList(List ** list);
void count(List ** list,int * i);
int countList(List * list);
List * searchList(List * list,int e);
List * reverse(List * first);

int main(void)
{
   List * list;
   List * tmp;
   int count1 = 0;
   createLinked(&list,5);
   printfList(&list);
   count(&list,&count1);
   printf("数量->%d\n",count1);
   printf("%d\n",countList(list));
   tmp =  searchList(list,1);
   printf("返回的值->%d\n",tmp->value);
   return 0;
}


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
   tmp = tmp->next;
   while(tmp->next != NULL)
   {
     printf("值->%d\n",tmp->value);
     tmp = tmp->next;    
   }
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

int  countList(List * list)
{
   int count = 0;
   List * temp = list;
   temp = temp->next;
   while(temp->next != NULL)
   {
      count++;
      temp = temp->next;
       
   }
  return count; 
}


List * searchList(List * list,int e)
{
    List * tmp;
    tmp = list;
    while(tmp->next != NULL)
    {
       if(tmp->value == e)
       {
           return tmp; 
       }
       tmp = tmp->next; 
    }
    return tmp;      
}

int dll_inser(List * head,List * rear,int value)
{
   register List * this;
   register List * next;
   register List * new;
   for(this = head;(next = this->fwd) != NULL;this = next)
   {
     if(value == next->value)
        return 0;
     if(next->value > value)
         break;
   } 
   new = (List*)malloc(sizeof(List));
   if(new == NULL)
   {   
     return -1;
   }
   new->value = value;
   if(this == head)
      head = new;
   else
      this->fwd = new;

   if(head == NULL || next == NULL)
      rear = new;
   else
      next->bwd = new;
   new->fwd = next;
   new->bwd = this; 
   return 0;
}


List * reverse(List * first)
{
   List * current;
   List * next;
   if(first != NULL)
   {
     for(current = NULL;next != NULL;first = next)
     {
         next = first->next;
         first->next = current;
         current = first;   
     }    
   }  
}
