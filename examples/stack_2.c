#include "stack.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Stack stack_int;
    Stack stack_char;
    stack_initialize(&stack_int, 10);
    stack_initialize(&stack_char, 10);
    
    stack_push_int(&stack_int, 3);
    stack_push_int(&stack_int, -23);

    stack_push_char(&stack_char, 'j');
    stack_push_char(&stack_char, 'k');

    printf("Stack (int):\n");
    printf("%d\n", stack_pop_int(&stack_int));
    printf("%d\n", stack_pop_int(&stack_int));

    printf("Stack (char):\n");
    printf("%c\n", stack_pop_char(&stack_char));
    printf("%c\n", stack_pop_char(&stack_char));

    stack_finalize(&stack_int);
    stack_finalize(&stack_char);
    
    return 0;
}
