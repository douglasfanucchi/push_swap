#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_algorithm_n2, itShouldSortTheStackWithTwoElementsUsingBubbleSortAdaption) {
    t_stack a, b;
    ft_stack_init(&a);
    ft_stack_init(&b);
    ft_stack_push(&a, 1);
    ft_stack_push(&a, 2);

    t_state result = ft_bubble_sort(&a, &b);

    ASSERT_LT(0, result.total_ops);
    ASSERT_EQ(1, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(2, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_NE(nullptr, result.ops);

    ft_lstclear(&result.ops, free);
}
