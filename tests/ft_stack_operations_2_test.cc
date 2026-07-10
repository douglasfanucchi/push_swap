#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

static t_bool	ft_int_eq(int a, int b)
{
	return (a == b);
}

TEST(ft_stack_find_offset, itShouldSearchForAnElementInTheWholeStackThatSatisfiesCallback) {
	t_dlist	node_1, node_2, node_3;
	t_stack	stack;
	t_substack substack;
	stack.size = 3;
	stack.head = &node_1;
	node_1.next = &node_2;
	node_1.prev = &node_3;
	node_1.n = 42;
	node_2.prev = &node_1;
	node_2.next = &node_3;
	node_2.n = 43;
	node_3.prev = &node_2;
	node_3.next = &node_1;
	node_3.n = 44;
	substack.start = 0;
	substack.size = stack.size;

	int result = ft_stack_find_offset(&stack, substack, 44, ft_int_eq);

	ASSERT_EQ(2, result);
}
