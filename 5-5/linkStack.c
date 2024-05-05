#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

typedef struct STACK_NODE{
  STACK_TYPE value;
  struct STACK_NODE *next;
}StackNode;

static StackNode * stack;

int is_empty(void){
  return stack == NULL;
}

int is_full(void)
{
  return FALSE;
}


void pop(void)
{
   StackNode * first_node;
   assert(!is_empty());
   first_node = stack;
   stack = stack-next;
   free(first_node);
}

void destory_stack(void)
{
   while(!is_empty())
      pop();
}

STACK_TYPE top(void)
{
  assert(!is_empty());
  return stack->value;
}

void push(STACK_TYPE value)
{
   StackNode * new;
   new = malloc(sizeof(StackNode));
   new->value = value; 
   new->next = stack;
   stack = new;
}





