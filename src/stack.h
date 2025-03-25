#ifndef STACK_H
#define STACK_H

typedef struct Stack
{
    void **array;
    int top;
    int size;
} Stack;

int stack_initialize(Stack *stack, int size);

int stack_push(Stack *stack, void *value);

int stack_push_int(Stack *stack, const int value);

void *stack_pop(Stack *stack);

int stack_pop_int(Stack *stack);

void stack_finalize(Stack *stack);

#endif
