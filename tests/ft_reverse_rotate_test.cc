#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_reverse_rotate, itShouldReverseRotateStackA) {
    t_stack a;
    ft_stack_init(&a);
    ft_stack_push(&a, 41);
    ft_stack_push(&a, 42);
    ft_stack_push(&a, 43);

    t_operations operation = ft_reverse_rotate_a(&a, NULL);

    ASSERT_EQ(rra, operation);
    ASSERT_EQ(41, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(43, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(42, ft_stack_peek(&a));
    ft_stack_pop(&a);
}
