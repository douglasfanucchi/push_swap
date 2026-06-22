#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
    #include <fcntl.h>
    #include <unistd.h>
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

TEST(ft_state, itShouldPrintOperations) {
    t_state state;
    t_list node_1, node_2;
    state.ops = &node_1;
    node_1.content = (void *)"sa";
    node_1.next = &node_2;
    node_2.content = (void *)"pb";
    node_2.next = NULL;

    int stdout = dup(1), fd[2];
    int piped = pipe2(fd, O_NONBLOCK);
    dup2(fd[1], 1);

    int result = ft_state_print(&state);
    dup2(stdout, 1);

    char buffer[7];
    int readed = read(fd[0], buffer, 6);
    buffer[6] = 0;
    ASSERT_STREQ("sa\npb\n", buffer);
    ASSERT_EQ(6, result);
}

TEST(ft_state, itShouldGetTheAmountOfSwapAOperations) {
    t_state state;
    state.count_ops[sa] = 42;

    int result = ft_state_get_operation_count(&state, sa);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfSwapBOperations) {
    t_state state;
    state.count_ops[sb] = 42;

    int result = ft_state_get_operation_count(&state, sb);

    ASSERT_EQ(42, result);
}
