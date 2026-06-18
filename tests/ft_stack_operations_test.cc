#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
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

TEST(ft_stack, itShouldRotateAStackWithOneElement) {
	t_stack stack;
	t_dlist node;
	node.n = 42;
	node.next = &node;
	node.prev = &node;
	stack.size = 1;
	stack.head = &node;

	ft_stack_rotate(&stack);

	ASSERT_EQ(42, stack.head->n);
	ASSERT_EQ(stack.head, stack.head->next);
	ASSERT_EQ(stack.head, stack.head->prev);
}


TEST(ft_stack, itShouldRotateAStackWithMoreThanOneElement) {
	t_stack stack;
	t_dlist node_1, node_2, node_3;
	node_1.n = 42;
	node_1.next = &node_2;
	node_1.prev = &node_3;
	node_2.n = 43;
	node_2.prev = &node_1;
	node_2.next = &node_3;
	node_3.n = 44;
	node_3.prev = &node_2;
	node_3.next = &node_1;
	stack.size = 3;
	stack.head = &node_1;

	ft_stack_rotate(&stack);

	ASSERT_EQ(43, stack.head->n);
	ASSERT_EQ(&node_2, stack.head);
	ASSERT_EQ(&node_1, stack.head->prev);
	ASSERT_EQ(&node_3, stack.head->next);
}


TEST(ft_stack, itShouldReverseRotateAStackWithOneElement) {
	t_stack stack;
	t_dlist node;
	node.n = 42;
	node.next = &node;
	node.prev = &node;
	stack.size = 1;
	stack.head = &node;

	ft_stack_reverse_rotate(&stack);

	ASSERT_EQ(42, stack.head->n);
	ASSERT_EQ(stack.head, stack.head->next);
	ASSERT_EQ(stack.head, stack.head->prev);
}

TEST(ft_stack, itShouldReverseRotateAStackWithMoreThanOneElement) {
	t_stack stack;
	t_dlist node_1, node_2, node_3;
	node_1.n = 42;
	node_1.next = &node_2;
	node_1.prev = &node_3;
	node_2.n = 43;
	node_2.prev = &node_1;
	node_2.next = &node_3;
	node_3.n = 44;
	node_3.prev = &node_2;
	node_3.next = &node_1;
	stack.size = 3;
	stack.head = &node_1;

	ft_stack_reverse_rotate(&stack);

	ASSERT_EQ(44, stack.head->n);
	ASSERT_EQ(&node_3, stack.head);
	ASSERT_EQ(&node_2, stack.head->prev);
	ASSERT_EQ(&node_1, stack.head->next);
}
