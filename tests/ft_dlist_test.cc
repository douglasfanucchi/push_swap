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
