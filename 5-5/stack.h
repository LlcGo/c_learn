#define STACK_TYPE int

void push(STACK_TYPE value);

void pop(void);

STACK_TYPE top(void);

int is_empty(void);

int is_full(void);

void create_stack(size_t size);

void destory_stack(void);
