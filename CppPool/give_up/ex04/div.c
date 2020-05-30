/*
** EPITECH PROJECT, 2020
** cpp_d02 - ex04
** File description:
** div.c
*/

#include "castmania.h"
#include <stdio.h>

int integer_div(int a, int b)
{
    if (b == 0)
        return 0;
    return a/b;
}

float decimale_div(int a, int b)
{
    return a/b;
}

void exec_div(division_t *operation)
{
    integer_op_t *inte = operation->div_op;
    decimale_op_t *deci = operation->div_op;

    if (operation->div_type == INTEGER)
        inte->res = integer_div(inte->a, inte->b);
    if (operation->div_type == DECIMALE)
        deci->res = decimale_div(deci->a, deci->b);
}


static void test_print(void)
{
    int i = 5;
    float f = 42.5;
    printf("Print i : %i", i);
    printf("Print f : %f", f);
}

static  void  test_div_op(integer_op_t *int_op , instruction_t *inst)
{
    division_t  div;
    div.div_type = INTEGER;
    div.div_op = int_op;
    inst ->operation = &div;
    printf("10 / 3 = ");
    exec_instruction(DIV_OPERATION , inst);
    printf("Indeed  10 / 3 = %d\n\n", int_op ->res);
}

static  void  test_operations(void)
{
    integer_op_t  int_op;
    instruction_t  inst;
    int_op.a = 10;
    int_op.b = 3;
    inst.output_type = VERBOSE;
    test_div_op (&int_op , &inst);
}

int  main(void)
{
    test_print();
    printf("\n");
    test_operations ();
    return (0);
}