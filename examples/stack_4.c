#include "stack.h"
#include <stdio.h>

int main(void)
{
    Stack stack;

    stack_initialize(&stack, 2);

    stack_push_str(&stack, "three");
    stack_push_str(&stack, "two");
    stack_push_str(&stack, "one");

    printf("%s\n", stack_pop_str(&stack));
    printf("%s\n", stack_pop_str(&stack));
    printf("%s\n", stack_pop_str(&stack));

    stack_finalize(&stack);
    
    return 0;
}
