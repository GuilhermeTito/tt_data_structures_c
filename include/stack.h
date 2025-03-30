#ifndef STACK_H
#define STACK_H

typedef struct Stack
{
    void **array;
    int top;
    int size;
} Stack;

int stack_initialize(Stack *stack, unsigned int size);

int stack_resize(Stack *stack, unsigned int new_size);

int stack_push(Stack *stack, void *value);

int stack_push_int(Stack *stack, const int value);

int stack_push_char(Stack *stack, const char value);

int stack_push_float(Stack *stack, const float value);

int stack_push_double(Stack *stack, const double value);

int stack_push_str(Stack *stack, char *value);

void *stack_pop(Stack *stack);

int stack_pop_int(Stack *stack);

char stack_pop_char(Stack *stack);

float stack_pop_float(Stack *stack);

double stack_pop_double(Stack *stack);

char *stack_pop_str(Stack *stack);

void stack_finalize(Stack *stack);

#endif
