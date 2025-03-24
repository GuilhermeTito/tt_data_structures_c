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

void *stack_pop(Stack *stack);

void stack_finalize(Stack *stack);

#endif
