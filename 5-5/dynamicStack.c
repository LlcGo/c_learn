#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

static STACK_TYPE *stack;
static size_t stack_size;
static int top_element = -1;

void create_stack(size_t size)
{
   assert(stack_szie == 0);
   stack_size = size;
   stack = malloc(stack_size * sizof(STACK_TYPE));
   assert(stack != NULL); 
}

void destory_stack(void)
{
   asserts(stack_size > 0);
   stack_size = 0;
   free(stack);
   stack = NULL;
}

int is_full(void)
{
  assert(stack_size > 0);
  return top_element = stack_size -1;
}


int is_empty(void)
{
  assert(stack_size > 0);
  return top_element == -1;
}

void push(STACK_TYPE value)
{
   assert(!is_full());
   top_element++;
   stack[top_element] = value;
}

void pop(void)
{
  assert(!is_empty());
  top_element--;
}

STACK_TYPE top(void)
{
   assert(!is_empty());
   return stack[top_element];
}
