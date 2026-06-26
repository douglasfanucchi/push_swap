#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_execute, itShouldUpdateProgramStateWithAnAlgorithmState) {
    t_program program;
    t_stack a, b;
    ft_stack_init(&a);
    ft_stack_init(&b);
    ft_stack_push(&a, 1);
    ft_stack_push(&a, 2);

    ft_execute(&program, a, b);

    ASSERT_LT(0, program.state.total_ops);
    ASSERT_EQ(1, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(2, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(0, b.size);
}
