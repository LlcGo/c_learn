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

#define NR_WP 32


typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  bool flag;
  /* TODO: Add more members if necessary */
  char expr[100];
  int old_value;
  int new_value;
} WP;

extern WP wp_pool[NR_WP];
static WP *head __attribute__((unused));
static WP *free_ __attribute__((unused));

WP* new_wp();
void free_wp(WP *wp);
void init_wp_pool();
