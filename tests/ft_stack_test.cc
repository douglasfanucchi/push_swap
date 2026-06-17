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

TEST(ft_stack, itShouldPushAnElementIntoAnEmptyStack) {
	t_stack stack;
	stack.size = 0;
	stack.head = NULL;

	int size = ft_stack_push(&stack, 42);

	ASSERT_EQ(1, size);
	ASSERT_EQ(1, stack.size);
	ASSERT_NE(nullptr, stack.head);
	ASSERT_EQ(42, stack.head->n);

	free(stack.head);
}
