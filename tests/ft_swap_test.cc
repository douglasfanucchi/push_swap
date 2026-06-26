#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_swap, itShouldSwapElementFromStackA) {
    t_stack a;
    ft_stack_init(&a);
    ft_stack_push(&a, 42);
    ft_stack_push(&a, 43);

    t_operations operation = ft_swap_a(&a, NULL);

    ASSERT_EQ(sa, operation);
    ASSERT_EQ(42, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(43, ft_stack_peek(&a));
    ft_stack_pop(&a);
}

TEST(ft_swap, itShouldSwapElementFromStackB) {
    t_stack b;
    ft_stack_init(&b);
    ft_stack_push(&b, 42);
    ft_stack_push(&b, 43);

    t_operations operation = ft_swap_b(NULL, &b);

    ASSERT_EQ(sb, operation);
    ASSERT_EQ(42, ft_stack_peek(&b));
    ft_stack_pop(&b);
    ASSERT_EQ(43, ft_stack_peek(&b));
    ft_stack_pop(&b);
}

TEST(ft_swap, itShouldSwapElementFromBothStacks) {
    t_stack a, b;
    ft_stack_init(&a);
    ft_stack_init(&b);
    ft_stack_push(&a, 42);
    ft_stack_push(&a, 43);
    ft_stack_push(&b, 42);
    ft_stack_push(&b, 43);

    t_operations operation = ft_swap_ss(&a, &b);

    ASSERT_EQ(ss, operation);
    ASSERT_EQ(42, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(43, ft_stack_peek(&a));
    ft_stack_pop(&a);
    ASSERT_EQ(42, ft_stack_peek(&b));
    ft_stack_pop(&b);
    ASSERT_EQ(43, ft_stack_peek(&b));
    ft_stack_pop(&b);
}
