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

TEST(ft_stack, itShouldPopAnElementFromAStack) {
	t_stack stack;
	t_dlist	*node = (t_dlist *)malloc(sizeof(t_dlist));
	node->n = 42;
	node->next = node;
	node->prev = node;
	stack.size = 1;
	stack.head = node;

	int result = ft_stack_pop(&stack);

	ASSERT_EQ(0, result);
	ASSERT_EQ(0, stack.size);
	ASSERT_EQ(nullptr, stack.head);
}


TEST(ft_stack, itShouldPeekTheElementAtTheTopOfStack) {
	t_stack stack;
	t_dlist node;
	node.n = 42;
	node.next = &node;
	node.prev = &node;
	stack.size = 1;
	stack.head = &node;

	int result = ft_stack_peek(&stack);

	ASSERT_EQ(42, result);
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
