#include "stack.h"
#include <stdio.h>

int main(void)
{
    Stack stack_int;
    Stack stack_char;
    Stack stack_float;
    Stack stack_double;
    Stack stack_str;
    
    stack_initialize(&stack_int, 10);
    stack_initialize(&stack_char, 10);
    stack_initialize(&stack_float, 10);
    stack_initialize(&stack_double, 10);
    stack_initialize(&stack_str, 10);
    
    stack_push_int(&stack_int, 3);
    stack_push_int(&stack_int, -23);

    stack_push_char(&stack_char, 'j');
    stack_push_char(&stack_char, 'k');

    stack_push_float(&stack_float, 43.4f);
    stack_push_float(&stack_float, 1.2f);

    stack_push_double(&stack_double, 99.99);
    stack_push_double(&stack_double, 17.2);

    stack_push_str(&stack_str, "World");
    stack_push_str(&stack_str, "Hello");

    printf("Stack (int):\n");
    printf("%d\n", stack_pop_int(&stack_int));
    printf("%d\n", stack_pop_int(&stack_int));

    printf("Stack (char):\n");
    printf("%c\n", stack_pop_char(&stack_char));
    printf("%c\n", stack_pop_char(&stack_char));

    printf("Stack (float):\n");
    printf("%f\n", stack_pop_float(&stack_float));
    printf("%f\n", stack_pop_float(&stack_float));

    printf("Stack (double):\n");
    printf("%f\n", stack_pop_double(&stack_double));
    printf("%f\n", stack_pop_double(&stack_double));

    printf("Stack (string):\n");
    printf("%s\n", stack_pop_str(&stack_str));
    printf("%s\n", stack_pop_str(&stack_str));

    stack_finalize(&stack_int);
    stack_finalize(&stack_char);
    stack_finalize(&stack_float);
    stack_finalize(&stack_double);
    stack_finalize(&stack_str);
    
    return 0;
}
