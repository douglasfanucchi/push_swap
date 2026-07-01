#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_execute_algorithms, itShouldReturnA_nlogn_AlgorithmWhenDisorderIsOneAndStrategyAdaptative) {
	t_stack a;
	ft_stack_init(&a);
	ft_stack_push(&a, 0);
	ft_stack_push(&a, 1);

	t_state result = ft_execute_algorithms(adaptative, 1, &a);

	ASSERT_EQ(2, a.size);
	ASSERT_EQ(1, ft_stack_get_nth_number(&a, 1));
	ASSERT_EQ(0, ft_stack_get_nth_number(&a, 2));
	ASSERT_STREQ("O(nlogn)", result.complexity);
	ASSERT_NE(nullptr, result.ops);
	ASSERT_LT(0, result.total_ops);

	ft_state_clear(&result);
	ft_stack_clear(&a);
}

TEST(ft_execute_algorithms, itShouldReturnA_nsqrtn_AlgorithmWhenDisorderIsBetween_0_2_And_0_5_StrategyAdaptative) {
	t_stack a;
	ft_stack_init(&a);
	ft_stack_push(&a, 2);
	ft_stack_push(&a, 3);
	ft_stack_push(&a, 4);
	ft_stack_push(&a, 1);
	ft_stack_push(&a, 0);

	t_state result = ft_execute_algorithms(adaptative, 0.30, &a);

	ASSERT_EQ(5, a.size);
	ASSERT_EQ(0, ft_stack_get_nth_number(&a, 1));
	ASSERT_EQ(1, ft_stack_get_nth_number(&a, 2));
	ASSERT_EQ(4, ft_stack_get_nth_number(&a, 3));
	ASSERT_EQ(3, ft_stack_get_nth_number(&a, 4));
	ASSERT_EQ(2, ft_stack_get_nth_number(&a, 5));
	ASSERT_STREQ("O(n√n)", result.complexity);
	ASSERT_NE(nullptr, result.ops);
	ASSERT_LT(0, result.total_ops);

	ft_state_clear(&result);
	ft_stack_clear(&a);
}

TEST(ft_execute_algorithms, itShouldReturnA_n2_AlgorithmWhenDisorderIsLessThan_0_2_And_StrategyAdaptative) {
	t_stack a;
	ft_stack_init(&a);
	ft_stack_push(&a, 3);
	ft_stack_push(&a, 4);
	ft_stack_push(&a, 2);
	ft_stack_push(&a, 1);
	ft_stack_push(&a, 0);

	t_state result = ft_execute_algorithms(adaptative, 0.10, &a);

	ASSERT_EQ(5, a.size);
	ASSERT_EQ(0, ft_stack_get_nth_number(&a, 1));
	ASSERT_EQ(1, ft_stack_get_nth_number(&a, 2));
	ASSERT_EQ(2, ft_stack_get_nth_number(&a, 3));
	ASSERT_EQ(4, ft_stack_get_nth_number(&a, 4));
	ASSERT_EQ(3, ft_stack_get_nth_number(&a, 5));
	ASSERT_STREQ("O(n²)", result.complexity);
	ASSERT_NE(nullptr, result.ops);
	ASSERT_LT(0, result.total_ops);

	ft_state_clear(&result);
	ft_stack_clear(&a);
}

TEST(ft_execute_algorithms, itShouldReturnA_n2_AlgorithmWhenStrategyIsSimple) {
	t_stack a;
	ft_stack_init(&a);
	ft_stack_push(&a, 0);
	ft_stack_push(&a, 1);
	ft_stack_push(&a, 2);
	ft_stack_push(&a, 3);
	ft_stack_push(&a, 4);

	t_state result = ft_execute_algorithms(simple, 1, &a);

	ASSERT_EQ(5, a.size);
	ASSERT_EQ(4, ft_stack_get_nth_number(&a, 1));
	ASSERT_EQ(3, ft_stack_get_nth_number(&a, 2));
	ASSERT_EQ(2, ft_stack_get_nth_number(&a, 3));
	ASSERT_EQ(1, ft_stack_get_nth_number(&a, 4));
	ASSERT_EQ(0, ft_stack_get_nth_number(&a, 5));
	ASSERT_STREQ("O(n²)", result.complexity);
	ASSERT_NE(nullptr, result.ops);
	ASSERT_LT(0, result.total_ops);

	ft_state_clear(&result);
	ft_stack_clear(&a);
}

TEST(ft_execute_algorithms, itShouldReturnA_nsqrtn_AlgorithmWhenStrategyIsMedium) {
	t_stack a;
	ft_stack_init(&a);
	ft_stack_push(&a, 0);
	ft_stack_push(&a, 1);
	ft_stack_push(&a, 2);
	ft_stack_push(&a, 3);
	ft_stack_push(&a, 4);

	t_state result = ft_execute_algorithms(medium, 1, &a);

	ASSERT_EQ(5, a.size);
	ASSERT_EQ(4, ft_stack_get_nth_number(&a, 1));
	ASSERT_EQ(3, ft_stack_get_nth_number(&a, 2));
	ASSERT_EQ(2, ft_stack_get_nth_number(&a, 3));
	ASSERT_EQ(1, ft_stack_get_nth_number(&a, 4));
	ASSERT_EQ(0, ft_stack_get_nth_number(&a, 5));
	ASSERT_STREQ("O(n√n)", result.complexity);
	ASSERT_NE(nullptr, result.ops);
	ASSERT_LT(0, result.total_ops);

	ft_state_clear(&result);
	ft_stack_clear(&a);
}

static void	ft_do_nothing_test(void *node)
{
	(void)node;
}

TEST(ft_execute_algorithms, itShouldInitializeListOfAlgorithms) {
	t_list	*algorithms[3];
	algorithms[0] = NULL;
	algorithms[1] = NULL;
	algorithms[2] = NULL;

	ft_initialize_algorithms(algorithms);

	ASSERT_NE(nullptr, algorithms[simple]);
	ASSERT_NE(nullptr, algorithms[medium]);
	ASSERT_NE(nullptr, algorithms[complex]);

	ft_lstclear(&algorithms[simple], ft_do_nothing_test);
	ft_lstclear(&algorithms[medium], ft_do_nothing_test);
	ft_lstclear(&algorithms[complex], ft_do_nothing_test);
}
