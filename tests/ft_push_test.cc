#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_push, itShouldPushAnElementFromStackBToStackA) {
    t_stack a, b;
    ft_stack_init(&a);
    ft_stack_init(&b);
    ft_stack_push(&b, 1);

    t_operations operation = ft_push_a(&a, &b);

    ASSERT_EQ(pa, operation);
    ASSERT_EQ(1, ft_stack_peek(&a));
    ASSERT_EQ(1, a.size);
    ASSERT_EQ(0, b.size);

    ft_stack_clear(&a);
}
