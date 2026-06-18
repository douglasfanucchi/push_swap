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
