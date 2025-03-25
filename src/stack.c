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

int stack_push_int(Stack *stack, const int value)
{
    int *ptr = (int*) malloc(sizeof(int));
    *ptr = value;

    return stack_push(stack, ptr);
}

void *stack_pop(Stack *stack)
{
    if(stack->top < 0)
        return NULL;

    return stack->array[stack->top--];
}

int stack_pop_int(Stack *stack)
{
    int *ptr = (int*) stack_pop(stack);
    
    if(!ptr)
        return 0;
        
    int value = *ptr;
    free(ptr);
    return value;
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
