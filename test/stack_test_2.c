#include "..\src\stack.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Stack stack;
    stack_initialize(&stack, 10);
    
    stack_push_int(&stack, 3);
    stack_push_int(&stack, 1254);
    stack_push_int(&stack, -23);

    printf("%d\n", stack_pop_int(&stack));
    printf("%d\n", stack_pop_int(&stack));
    printf("%d\n", stack_pop_int(&stack));

    stack_finalize(&stack);
    
    return 0;
}
