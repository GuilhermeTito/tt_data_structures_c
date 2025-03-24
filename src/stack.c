#include "stack.h"
#include <stdlib.h>

int stack_initialize(Stack *stack, int size)
{
    stack->array = malloc(size * sizeof(void*));

    if(!stack->array)
        return 0;

    stack->top = -1;
    stack->size = size;

    return 1;
}

int stack_push(Stack *stack, void *value)
{
    if(stack->top >= stack->size - 1)
        return 0;

    stack->array[++stack->top] = value;

    return 1;
}

void *stack_pop(Stack *stack)
{
    if(stack->top < 0)
        return NULL;

    return stack->array[stack->top--];
}

void stack_finalize(Stack *stack)
{
    if(!stack)
        return;

    if(!stack->array)
        return;

    for(int i = 0; i < stack->size; i++)
        free(stack->array[i]);

    free(stack->array);
}
