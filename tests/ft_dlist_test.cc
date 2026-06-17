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

TEST(ft_dlist, itShouldAddAnElementIntoTheBackOfAnEmptyList) {
	t_dlist	*list = NULL;
	t_dlist node;
	node.n = 42;
	node.next = NULL;
	node.prev = NULL;

	ft_dlstadd_back(&list, &node);

	ASSERT_NE(nullptr, list);
	ASSERT_EQ(&node, list);
	ASSERT_EQ(&node, list->next);
	ASSERT_EQ(&node, list->prev);
}

TEST(ft_dlist, itShouldAddAnElementIntoTheBackOfNonEmptyList) {
	t_dlist *list, tail_node, new_node;
	list = &tail_node;
	tail_node.prev = &tail_node;
	tail_node.next = &tail_node;
	tail_node.n = 42;
	new_node.n = 43;
	new_node.next = NULL;
	new_node.prev = NULL;

	ft_dlstadd_back(&list, &new_node);

	ASSERT_EQ(&tail_node, list);
	ASSERT_EQ(&new_node, list->prev);
	ASSERT_EQ(&new_node, list->next);
	ASSERT_EQ(42, list->n);
	ASSERT_EQ(list, new_node.prev);
	ASSERT_EQ(list, new_node.next);
	ASSERT_EQ(43, new_node.n);
}

TEST(ft_dlist, itShouldPopAnElementFromAListThatHasOneNode) {
	t_dlist *list, head_node;
	list = &head_node;
	head_node.prev = &head_node;
	head_node.next = &head_node;
	head_node.n = 43;

	t_dlist *result = ft_dlst_pop(&list);

	ASSERT_EQ(nullptr, list);
	ASSERT_NE(nullptr, result);
	ASSERT_EQ(nullptr, result->prev);
	ASSERT_EQ(nullptr, result->next);
	ASSERT_EQ(43, result->n);
}

TEST(ft_dlist, itShouldPopAnElementFromAListThatHasTwoNodes) {
	t_dlist *list, head_node, second_node;
	list = &head_node;
	head_node.prev = &second_node;
	head_node.next = &second_node;
	head_node.n = 42;
	second_node.n = 43;
	second_node.prev = &head_node;
	second_node.next = &head_node;

	t_dlist *result = ft_dlst_pop(&list);

	ASSERT_EQ(&second_node, list);
	ASSERT_EQ(&second_node, second_node.prev);
	ASSERT_EQ(list, second_node.next);
	ASSERT_EQ(43, list->n);
	ASSERT_EQ(nullptr, result->prev);
	ASSERT_EQ(nullptr, result->next);
	ASSERT_EQ(42, result->n);
}
