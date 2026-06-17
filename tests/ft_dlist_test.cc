#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_dlist, itShouldCreateANewNodeOfADlist) {
	t_dlist	*node = NULL;

	node = ft_dlstnew(42);

	ASSERT_NE(nullptr, node);
	ASSERT_EQ(42, node->n);
	ASSERT_EQ(nullptr, node->next);
	ASSERT_EQ(nullptr, node->prev);
	free(node);
}

TEST(ft_dlist, itShouldAddAnElementInFrontOfAnEmptyList) {
	t_dlist	*list = NULL;
	t_dlist node;
	node.n = 42;
	node.next = NULL;
	node.prev = NULL;

	ft_dlstadd_front(&list, &node);

	ASSERT_NE(nullptr, list);
	ASSERT_EQ(&node, list);
	ASSERT_EQ(&node, list->next);
	ASSERT_EQ(&node, list->prev);
}

TEST(ft_dlist, itShouldAddAnElementInFrontOfANonEmptyList) {
	t_dlist *list, head_node, new_node;
	list = &head_node;
	head_node.prev = &head_node;
	head_node.next = &head_node;
	head_node.n = 43;
	new_node.n = 42;
	new_node.next = NULL;
	new_node.prev = NULL;

	ft_dlstadd_front(&list, &new_node);

	ASSERT_EQ(&new_node, list);
	ASSERT_EQ(&head_node, list->prev);
	ASSERT_EQ(&head_node, list->next);
	ASSERT_EQ(42, list->n);
	ASSERT_EQ(list, head_node.prev);
	ASSERT_EQ(list, head_node.next);
	ASSERT_EQ(43, head_node.n);
}
