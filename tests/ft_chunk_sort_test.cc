#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_push_range, itShouldPushAllElementsFromStackAToStackB) {
    t_stack *stacks[2];
    t_stack a;
    t_stack b;
    t_state state;
    ft_state_init(&state);
    ft_stack_init(&a);
    ft_stack_init(&b);
    ft_stack_push(&a, 0);
    ft_stack_push(&a, 2);
    int range[2];
    range[0] = 0;
    range[1] = 5;
    stacks[0] = &a;
    stacks[1] = &b;

    int result = ft_push_range(range, stacks, &state, pb);

    ASSERT_EQ(2, result);
    ASSERT_EQ(0, a.size);
    ASSERT_EQ(2, b.size);
    ft_stack_clear(&b);
    ft_state_clear(&state);
}

TEST(ft_push_range, itShouldPushToStackBOnlyElementsThatIsInTheRange) {
    t_stack *stacks[2];
    t_stack a;
    t_stack b;
    t_state state;
    ft_state_init(&state);
    ft_stack_init(&a);
    ft_stack_init(&b);
    ft_stack_push(&a, 0);
    ft_stack_push(&a, 5);
    ft_stack_push(&a, 1);
    ft_stack_push(&a, 3);
    ft_stack_push(&a, 2);
    ft_stack_push(&a, 4);
    int range[2];
    range[0] = 3;
    range[1] = 5;
    stacks[0] = &a;
    stacks[1] = &b;

    int result = ft_push_range(range, stacks, &state, pb);

    ASSERT_EQ(3, result);
    ASSERT_EQ(3, a.size);
    ASSERT_EQ(3, b.size);
    ASSERT_EQ(5, ft_stack_peek(&b));
    ft_stack_rotate(&b);
    ASSERT_EQ(3, ft_stack_peek(&b));
    ft_stack_rotate(&b);
    ASSERT_EQ(4, ft_stack_peek(&b));
    ft_stack_clear(&a);
    ft_stack_clear(&b);
    ft_state_clear(&state);
}

TEST(ft_push_range, itShouldPushAllElementsFromStackBToStackA) {
    t_stack *stacks[2];
    t_stack a;
    t_stack b;
    t_state state;
    ft_state_init(&state);
    ft_stack_init(&a);
    ft_stack_init(&b);
    ft_stack_push(&b, 0);
    ft_stack_push(&b, 2);
    int range[2];
    range[0] = 0;
    range[1] = 5;
    stacks[0] = &b;
    stacks[1] = &a;

    int result = ft_push_range(range, stacks, &state, pa);

    ASSERT_EQ(2, result);
    ASSERT_EQ(2, a.size);
    ASSERT_EQ(0, b.size);
    ft_stack_clear(&a);
    ft_state_clear(&state);
}
