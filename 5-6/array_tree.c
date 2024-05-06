#include "tree.h"
#include <assert.h>
#include <stdio.h>

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE +1)

static TREE_TYPE tree[ARRAY_SIZE];

// 计算以恶节点左孩子的下标
static int left_child(int current)
{
  return current * 2;
}

//计算一个节点右孩子下标
static int right_child(int current)
{
  return current * 2 + 1;
}

void insert(TREE_TYPE value)
{
  int current;
  assert(value != 0);
  // 从1开始查
  current = 1;
  
  while(tree[current] != 0)
  {
    if(value < tree[current])
    {
      current = left_child(current);
    }
    else
    {
      assert(value != tree[current])
      current = right_child(current);
    }
  }
  tree[current] = value;
}


TREE_TYPE * find(TREE_TYPE value)
{
  int current;
  current = 1;
  while(current < ARRAY_SIZE && tree[current] != value)
  {
    if(value < tree[current])
    {
        current = left_child(current);  
    }
    else
    {
        current = right_child(current);
    } 
  }
  if(current < ARRAY_SIZE)
      return tree + current;
  else
      return 0; 
}

static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value))
{
  if(current < ARRAY_SIZE && tree[current] != 0)
  {
     callback(tree[current]);
     do_pre_order_traverse(left_child(tree[current]),callback);
     do_pre_order_traverse(right_child(tree[current]),callback); 
  }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
  do_pre_order_traverse(1,callback); 
}

