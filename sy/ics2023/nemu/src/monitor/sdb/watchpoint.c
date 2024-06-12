/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "sdb.h"
#include "watchpoint.h"
#define NR_WP 32


WP wp_pool[NR_WP] = {};

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].flag = false;
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
   for(WP *tmp = free_; tmp != NULL; tmp = tmp->next)
   {
	   if(!tmp->flag)
	   {
		   tmp->flag = true;
		   if(head == NULL){
		       head = tmp;
		   }
		   return tmp;
	   }
   }
   printf("voer max");   
   assert(0);
   return NULL;
}
void free_wp(WP *wp){
      if(wp->NO == head->NO){
	  free_->flag = false;
	  head = NULL;
	  printf("Delete watchpoint success.\n");
	  return;
      }
      for(WP *tmp = head; tmp->next != NULL; tmp = tmp->next)
      {
	      if(wp->NO == tmp->next->NO)
	      {
		   tmp->next = tmp->next->next;   
		   tmp->next->flag = false;
		   printf("free success.\n");
		   return;
	      }
      }
      printf("no wp");
      assert(0);
}

