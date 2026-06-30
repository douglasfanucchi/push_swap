#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_execute_algorithm, itShouldReturnA_nlogn_AlgorithmWhenDisorderIsOneAndStrategyAdaptative) {
	t_stack a;
	ft_stack_init(&a);
	ft_stack_push(&a, 0);
	ft_stack_push(&a, 1);

	t_state result = ft_execute_algorithm(adaptative, 1, &a);

	ASSERT_EQ(2, a.size);
	ASSERT_EQ(1, ft_stack_get_nth_number(&a, 1));
	ASSERT_EQ(0, ft_stack_get_nth_number(&a, 2));
	ASSERT_STREQ("O(nlogn)", result.complexity);
	ASSERT_NE(nullptr, result.ops);
	ASSERT_LT(0, result.total_ops);

	ft_state_clear(&result);
	ft_stack_clear(&a);
}
