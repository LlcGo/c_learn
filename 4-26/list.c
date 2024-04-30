#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item,Node *pnode);

void InitList(List * plist)
{
  *plist = NULL;
}

bool ListIsEmpty(const List * plist)
{
  if(*plist == NULL)
      return true;
  else
      return false;
}

bool ListIsFull(const List * plist)
{
   Node * pt;
   bool full;
   
  pt = (Node *)malloc(sizeof(Node));
  if(pt == NULL)
     full = true;
  else
     full = false;
  free(pt);
  return full;
}


unsigned int ListItemCount(const List * plist)
{
  unsigned int count = 0;
  Node * pnode = * plist;
  while(pnode != NULL)
  {
    ++count;
    pnode = pnode->next; /*指向下一个节点*/ 
  }
  return count;
}

/*链表末尾添加项*/
bool AddItem(Item item,List * plist)
{
  Node * pnew;
  Node * scan = *plist;
  pnew = (Node*)malloc(sizeof(Node));
  if(pnew == NULL)
  {
     return false;
  }
  
  CopyToNode(item,pnew);
  pnew->next = NULL;
  if(scan == NULL)
  {
    *plist = pnew;
  }
  else
  {
    while (scan->next != NULL)
       scan = scan->next;
    scan->next = pnew; /*pnew + 末尾*/
  }
  return true;
}

/*把函数作用与链表中的每一项 遍历显示链表*/
void Traverse(const List * plist,void(*pfun)(Item item))
{
  Node * pnode = *plist;
  while(pnode != NULL)
  {
    (*pfun)(pnode->item);
    pnode = pnode->next;
  } 
}

/*释放内存*/
void FreeList(List * plist)
{
  Node * temp;
  while(*plist != NULL)
  {
    temp = (*plist)->next;
    free(temp);
    *plist = temp;     
  } 
}

static void CopyToNode(Item item,Node * pnode)
{
  pnode->item = item; /*拷贝结构*/
}

