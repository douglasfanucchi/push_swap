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
