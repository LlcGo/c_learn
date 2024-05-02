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
// 错的
List * reverse2(List * first);
//int dll_inser(List * head,List * rear,int value);
List *sll_reverse(List *rootp);
int sll_remove(List ** list,List * node);
int sll_remove2(List ** list,List * node);
int sll_remove3(List ** list,List * node);
int sll_remove5(List ** list,List * node);

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
   // tmp =  searchList(list,1);
   // printf("返回的值->%d\n",tmp->value);
   // tmp = sll_reverse(list);
   // tmp = reverse(list);
   // printf("-----------------------------\n");
   List * new =  (List*)malloc(sizeof(List));
   new->value = 2;
   sll_remove3(&list,new);
   printfList(&list);
   return 0;
}

int sll_remove5(List ** list,List * node)
{
   //先排除头节点删除的问题
   while((*list) != NULL && (*list)->value == node->value)
   {
      (*list) = (*list)->next;
   }
   if((*list) == NULL)
   {
      return 0;
   }
   List * tmp = *list;
   while(tmp->next != NULL)
   {
      if(tmp->next->value = node->value)
      {
         tmp->next =tmp->next->next;
         free(node);
      }
      else
      {
        tmp = tmp->next;
      }
   }
   return 0;

}


int sll_remove3(List ** list,List * node)
{
   List * pre, *curr;
   curr = *list;
   while(curr != NULL)
   {
       if(curr->value == node->value)
       {
           // 如果是头指针 没有移动过
           if(pre == NULL)
           {
              *list = curr->next; 
           }
           else
           {
              pre->next = curr->next;  
           }
           free(curr);
           return 1;
       }
      // 不相等 移动
      pre = curr;
      curr = curr->next;
   }
   return 0;
}

// 网上搜的方法坑的  我只想对这个哥们说：你一套流程跑完你的头节点指针 都到哪去都不知道了 还怎么遍历啊哥们，还怎么玩啊哥们
int sll_remove2(List ** list,List * node)
{
  List * tmp;
  // arrsert(node != NULL);
  while((tmp = *list)!=NULL)
  {
     if(tmp = node)
     {
      *list = tmp->next;
       free(node);
       return 1; 
     }
     list = &tmp->next;
  }
  return 0; 
}

int sll_remove(List ** list,List * node)
{
    List *  tmp = *list;
    List *  pre;
    while(tmp->next != NULL)
    {
       if(tmp->value == node->value)
       {
         // 找到了 
         break;
       }
       pre = tmp;
       tmp = tmp->next;  
    }
     // 尾部
    if(tmp->next == NULL)
    {
       pre->next = NULL;       
    }
    else
    {
      pre->next = pre->next->next;
    }
    
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



List * reverse(List * first)
{
   List * current;
   List * next;
   if(first != NULL)
   {
     for(current = NULL;first != NULL;first = next)
     {
         next = first->next;
         first->next = current;
         current = first;   
     }    
   }
   return current;  
}

List *sll_reverse(List *rootp)
{
    List * prev = NULL;
    List * curr = rootp;
    while (curr) {
        List * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 错的
List * reverse2(List * first)
{
  List * newfirst;
  List * p = first;
  List * q = first;
  if(first != NULL)
    return NULL;
  while(p->next != NULL)
  {
         q = p;
         p = p->next;     
  }
  newfirst = p;

  while(q->next != NULL)
  {
         p->next = q;
         p = q;
         q = q->next;
  }  
  q->next = NULL;
  return newfirst;  
}
