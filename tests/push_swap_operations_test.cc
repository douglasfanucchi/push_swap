#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(push_swap_operations, itShouldSwapElementFromStackA) {
    t_stack a;
    ft_stack_push(&a, 42);
    ft_stack_push(&a, 43);

    t_operations operation = ft_swap_a(&a, NULL);

    ASSERT_EQ(sa, operation);
    ASSERT_EQ(42, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(43, ft_stack_peek(&a));
    ft_stack_pop(&a);
}
