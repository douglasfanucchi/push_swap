#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
    #include <fcntl.h>
    #include <unistd.h>
    #include <strings.h>
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

TEST(ft_state, itShouldGetTheAmountOfSwapBothOperations) {
    t_state state;
    state.count_ops[ss] = 42;

    int result = ft_state_get_operation_count(&state, ss);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfPushAOperations) {
    t_state state;
    state.count_ops[pa] = 42;

    int result = ft_state_get_operation_count(&state, pa);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfPushBOperations) {
    t_state state;
    state.count_ops[pb] = 42;

    int result = ft_state_get_operation_count(&state, pb);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfRotateAOperations) {
    t_state state;
    state.count_ops[ra] = 42;

    int result = ft_state_get_operation_count(&state, ra);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfRotateBOperations) {
    t_state state;
    state.count_ops[rb] = 42;

    int result = ft_state_get_operation_count(&state, rb);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfRotateBothOperations) {
    t_state state;
    state.count_ops[rr] = 42;

    int result = ft_state_get_operation_count(&state, rr);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfReverseRotateAOperations) {
    t_state state;
    state.count_ops[rra] = 42;

    int result = ft_state_get_operation_count(&state, rra);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfReverseRotateBOperations) {
    t_state state;
    state.count_ops[rrb] = 42;

    int result = ft_state_get_operation_count(&state, rrb);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldGetTheAmountOfReverseRotateBothOperations) {
    t_state state;
    state.count_ops[rrr] = 42;

    int result = ft_state_get_operation_count(&state, rrr);

    ASSERT_EQ(42, result);
}

TEST(ft_state, itShouldUpdateStateByPassingSwapAOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, sa);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[sa]);
    ASSERT_STREQ("sa", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingSwapBOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, sb);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[sb]);
    ASSERT_STREQ("sb", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingSwapSwapOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, ss);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[ss]);
    ASSERT_STREQ("ss", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingPushAOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, pa);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[pa]);
    ASSERT_STREQ("pa", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingPushBOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, pb);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[pb]);
    ASSERT_STREQ("pb", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingRotateAOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, ra);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[ra]);
    ASSERT_STREQ("ra", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingRotateBOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, rb);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[rb]);
    ASSERT_STREQ("rb", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingRotateRotateOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, rr);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[rr]);
    ASSERT_STREQ("rr", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingReverseRotateAOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, rra);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[rra]);
    ASSERT_STREQ("rra", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingReverseRotateBOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, rrb);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[rrb]);
    ASSERT_STREQ("rrb", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldUpdateStateByPassingReverseRotateRotateOperation) {
    t_state state;
    bzero(&state, sizeof(t_state));

    t_bool result = ft_state_update(&state, rrr);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, state.total_ops);
    ASSERT_EQ(1, state.count_ops[rrr]);
    ASSERT_STREQ("rrr", (char *)state.ops->content);

    ft_lstclear(&state.ops, free);
}

TEST(ft_state, itShouldClearStateInstance) {
    t_state state;
    bzero(&state, sizeof(t_state));
    ft_lstadd_back(&state.ops, ft_lstnew(ft_strdup("sa")));
    state.count_ops[sa] = 1;
    state.total_ops = 1;

    ft_state_clear(&state);

    ASSERT_EQ(nullptr, state.ops);
    ASSERT_EQ(0, state.count_ops[sa]);
    ASSERT_EQ(0, state.total_ops);
}
