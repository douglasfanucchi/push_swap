#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

static t_operations	ft_swap_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (sa);
}

static t_operations	ft_swap_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (sb);
}

static t_operations	ft_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (ss);
}

static t_operations	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (pa);
}

TEST(push_swap, itShouldExecuteSwapOperationOnStackA) {
	t_state	state;
	t_stack	stack_a;
	state.count_ops[sa] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_swap_a);

	ASSERT_EQ(1, state.count_ops[sa]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("sa", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteSwapOperationOnStackB) {
	t_state	state;
	t_stack	stack_b;
	state.count_ops[sb] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, NULL, &stack_b, ft_swap_b);
	
	ASSERT_EQ(1, state.count_ops[sb]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("sb", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteSwapOperationOnBothStacks) {
	t_state	state;
	t_stack	stack_a, stack_b;
	state.count_ops[ss] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, &stack_b, ft_swap_ss);
	
	ASSERT_EQ(1, state.count_ops[ss]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("ss", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecutePushOperationOnStackA) {
	t_state	state;
	t_stack	stack_a, stack_b;
	state.count_ops[pa] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, &stack_b, ft_push_a);
	
	ASSERT_EQ(1, state.count_ops[pa]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("pa", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}
