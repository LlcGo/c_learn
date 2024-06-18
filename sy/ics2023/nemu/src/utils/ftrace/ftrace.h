#include <common.h>
#include <elf.h>
#include <stdio.h>
#include <string.h>

#define FT_CALL 0
#define FT_RET 1

/*
解析elf文件后所有函数的信息都放在 elf_funcs数组中
append在 elf_funcs中添加一条 function 信息
check_func 在 elf_funcs中查找指定内存地址区域内的函数信息，并返回指针
init_elf 在 init_ftracer中调用
*/

typedef struct __FUNC__INFO
{
    char func_name[64];
    paddr_t start;
    size_t size;
} FUNC_INFO;

#define MAX_ELF_FUNCS 256


FUNC_INFO *check_func(paddr_t addr);

// 拿到 elf 文件后初始化相关信息，填写好elf_funcs
void init_elf(const char *elf_file);


typedef struct __STACK_ENTRY_
{
    FUNC_INFO *cur_info;
    FUNC_INFO *des_info;
    paddr_t addr;
    int type;
    struct __STACK_ENTRY_ *next;
} STACK_ENTRY;

void append_entry(paddr_t cur, paddr_t des, int type);

void init_ftrace(const char *elf_file); // 初始化 stack_header,调用 init elf

void print_func_trace(); // 打印函数执行流程


