#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_stack, itShouldInitializeAStack) {
	t_stack	stack;

	ft_stack_init(&stack);

	ASSERT_EQ(0, stack.size);
	ASSERT_EQ(nullptr, stack.head);
}

TEST(ft_stack, itShouldClearTheStack) {
	t_stack stack;
	t_dlist *node = (t_dlist*)malloc(sizeof(t_dlist));
	node->n = 42;
	node->next = node;
	node->prev = node;
	stack.size = 1;
	stack.head = node;

	ft_stack_clear(&stack);

	ASSERT_EQ(nullptr, stack.head);
}

TEST(ft_stack, itShouldReturnANumberGivenItsPosition) {
	t_stack	stack;
	t_dlist node_1, node_2;
	stack.size = 2;
	stack.head = &node_1;
	node_1.n = 42;
	node_1.next = &node_2;
	node_1.prev = &node_2;
	node_2.prev = &node_1;
	node_2.next = &node_1;
	node_2.n = 43;

	int result = ft_stack_get_nth_number(&stack, 2);

	ASSERT_EQ(43, result);
}

static t_bool	ft_stack_number_lt(int a, int b)
{
	return (b < a);
}

TEST(ft_stack, itShouldreturnAnIndexOfTheFirstNumberThatSatisfiesACallback) {
	t_stack	stack;
	t_dlist node_1, node_2;
	stack.size = 2;
	stack.head = &node_1;
	node_1.n = 43;
	node_1.next = &node_2;
	node_1.prev = &node_2;
	node_2.prev = &node_1;
	node_2.next = &node_1;
	node_2.n = 42;

	int	result = ft_stack_find(&stack, 43, ft_stack_number_lt);

	ASSERT_EQ(1, result);
}

TEST(ft_stack, itShouldreturnNegativeOneWhenNoNumberSatisfiesACallback) {
	t_stack	stack;
	t_dlist node_1, node_2;
	stack.size = 2;
	stack.head = &node_1;
	node_1.n = 43;
	node_1.next = &node_2;
	node_1.prev = &node_2;
	node_2.prev = &node_1;
	node_2.next = &node_1;
	node_2.n = 42;

	int	result = ft_stack_find(&stack, 42, ft_stack_number_lt);

	ASSERT_EQ(-1, result);
}

TEST(ft_stack, itShouldCopyAnExistingStack) {
	t_stack	stack;
	t_dlist node_1, node_2;
	stack.size = 2;
	stack.head = &node_1;
	node_1.n = 43;
	node_1.next = &node_2;
	node_1.prev = &node_2;
	node_2.prev = &node_1;
	node_2.next = &node_1;
	node_2.n = 42;

	t_stack result = ft_stack_copy(&stack);

	ASSERT_EQ(2, result.size);
	ASSERT_EQ(43, result.head->n);
	ASSERT_EQ(42, result.head->next->n);

	ft_stack_clear(&result);
}
