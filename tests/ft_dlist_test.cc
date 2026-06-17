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
