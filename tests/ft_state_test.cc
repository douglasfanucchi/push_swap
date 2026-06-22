#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_state, itShouldInitializeState) {
    t_state state;

    ft_state_init(&state);

    ASSERT_EQ(0, state.total_ops);
    ASSERT_EQ(nullptr, state.ops);
    ASSERT_EQ(0, state.count_ops[sa]);
    ASSERT_EQ(0, state.count_ops[sb]);
    ASSERT_EQ(0, state.count_ops[ss]);
    ASSERT_EQ(0, state.count_ops[pa]);
    ASSERT_EQ(0, state.count_ops[pb]);
    ASSERT_EQ(0, state.count_ops[ra]);
    ASSERT_EQ(0, state.count_ops[rb]);
    ASSERT_EQ(0, state.count_ops[rr]);
    ASSERT_EQ(0, state.count_ops[rra]);
    ASSERT_EQ(0, state.count_ops[rrb]);
    ASSERT_EQ(0, state.count_ops[rrr]);
}
