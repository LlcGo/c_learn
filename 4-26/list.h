#ifndef LIST_H
#define LIST_Hi
#include <stdbool.h> /*c99特性*/

/*特定程序声明*/

#define TSIZE 45 /*存储电影名大小*/
struct film
{
  char title[TSIZE];
  int rating;
};


/*一般类型定义*/
typedef struct film Item;

typedef struct node
{
   Item item;
   struct node * next;
}Node;

typedef Node * list;

/*函数原型*/

/*初始化链表*/
void InitList(List * plist);

/*链表是否为空定义 plist 指向一个已初始化的链表*/
bool ListIsEmpty(const List * plist);

/*链表是否已满*/
bool ListIsFull(const List * plist);

/*查看链表长度*/
unsigned int ListItemCount(const List * plist);

/*链表末尾添加项*/
bool AddItem(Item item,List * plist);

/*把函数作用与链表中的每一项 遍历显示链表*/
void Traverse(const List * plist,viod(*pfun)(Item item));

/*释放内存*/
void FreeList(List * plist);
