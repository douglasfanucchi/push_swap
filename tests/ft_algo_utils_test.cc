#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_move_ith_to, itShouldMoveAnElementThatIsInTheFirstHalfOfTheStackAToTopByRotate) {
	t_stack	a;
	t_state	state;
	t_move move;
	move.from = 1;
	move.to = 0;
	ft_state_init(&state);
	ft_stack_init(&a);
	ft_stack_push(&a, 41);
	ft_stack_push(&a, 42);
	ft_stack_push(&a, 43);
	ft_stack_push(&a, 44);

	ft_move_ith_to(move, &state, &a, ra);

	ASSERT_EQ(1, state.total_ops);
	ASSERT_STREQ("ra", (char *)state.ops->content);
	ASSERT_EQ(43, ft_stack_peek(&a));

	ft_state_clear(&state);
	ft_stack_clear(&a);
}
