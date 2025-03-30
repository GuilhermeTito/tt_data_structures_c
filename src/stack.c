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

int stack_push_char(Stack *stack, const char value)
{
    char *ptr = (char*) malloc(sizeof(char));
    *ptr = value;

    return stack_push(stack, ptr);
}

int stack_push_float(Stack *stack, const float value)
{
    float *ptr = (float*) malloc(sizeof(float));
    *ptr = value;

    return stack_push(stack, ptr);
}

int stack_push_double(Stack *stack, const double value)
{
    double *ptr = (double*) malloc(sizeof(double));
    *ptr = value;

    return stack_push(stack, ptr);
}

int stack_push_str(Stack *stack, char *value)
{
    return stack_push(stack, value);
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

char stack_pop_char(Stack *stack)
{
    char *ptr = (char*) stack_pop(stack);
    
    if(!ptr)
        return '\0';

    char value = *ptr;
    free(ptr);
    return value;
}

float stack_pop_float(Stack *stack)
{
    float *ptr = (float*) stack_pop(stack);

    if(!ptr)
        return 0.0f;

    float value = *ptr;
    free(ptr);
    return value;
}

double stack_pop_double(Stack *stack)
{
    double *ptr = (double*) stack_pop(stack);

    if(!ptr)
        return 0.0;

    double value = *ptr;
    free(ptr);
    return value;
}

char *stack_pop_str(Stack *stack)
{
    return (char*) stack_pop(stack);
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
