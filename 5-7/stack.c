#include <stdio.h>
#include <string.h>
#define  ElementType int

struct Node
{
  ElementType Element;
  struct Node *  next;
}

typedef struct Node* stack;

int IsEmpty(stack s)
{
  return s->next == NULL;
}

int compare(char * c);

stack createStack(void)
{
  stack s = (stack)malloc(sizeof(Node));
  s->next = NULL;
  return s; 
}


void push(stack s,ElementType e)
{ 
   stack new = (stack *)malloc(sizeof(Node));
   new->element = e;
   new->next = s->next;
   s->next= new;
}

void pop(stack s)
{
  stack tmp = s->next;
  s->next = s->next->next;
  free(tmp);    
}

ElementType Top(stack s)
{
  if(!IsEmpty(s))
  {
    return s->next->value;
  }
  return 0;
}

int main(){
  char * c = "({)]";
  int compare(c);
}

int compare(char * c)
{
   int len = strlen(c);
   if(len % 2 !== 0)
   {
      return -1;
   }
   stack s =  createStack();
   while((*c) != '\0')
   {
      if((*c) == '(')
      {
         push(s,')');
      }  
      else if((*c) == '[')
      {
         push(s,']');     
      }
      else if((*c) == '{')
      {  
         push(s,'}');
      }
      else if(IsEmpty(s) || Top(s) != (*c))
      {
            return -1;
      }
      else
      {
          pop(s);
      }
   }
   if(!IsEmpty(s))
   {
      return -1;
   }
   return 0;
}

