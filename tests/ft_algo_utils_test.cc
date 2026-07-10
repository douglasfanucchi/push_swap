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

TEST(ft_move_ith_to, itShouldMoveAnElementThatIsInTheSecondHalfOfTheStackAToTheTopByReverseRotate) {
	t_stack	a;
	t_state	state;
	t_move move;
	move.from = 3;
	move.to = 0;
	ft_state_init(&state);
	ft_stack_init(&a);
	ft_stack_push(&a, 41);
	ft_stack_push(&a, 42);
	ft_stack_push(&a, 43);
	ft_stack_push(&a, 44);

	ft_move_ith_to(move, &state, &a, ra);

	ASSERT_EQ(1, state.total_ops);
	ASSERT_STREQ("rra", (char *)state.ops->content);
	ASSERT_EQ(41, ft_stack_peek(&a));

	ft_state_clear(&state);
	ft_stack_clear(&a);
}

TEST(ft_move_ith_to, itShouldMoveAnElementFromTopToTheEndByRotate) {
	t_stack	a;
	t_state	state;
	t_move move;
	move.from = 0;
	move.to = 3;
	ft_state_init(&state);
	ft_stack_init(&a);
	ft_stack_push(&a, 41);
	ft_stack_push(&a, 42);
	ft_stack_push(&a, 43);
	ft_stack_push(&a, 44);

	ft_move_ith_to(move, &state, &a, ra);

	ASSERT_EQ(1, state.total_ops);
	ASSERT_STREQ("ra", (char *)state.ops->content);
	ASSERT_EQ(44, ft_stack_get_nth_number(&a, 4));

	ft_state_clear(&state);
	ft_stack_clear(&a);
}

TEST(ft_move_ith_to, itShouldMoveAnElementThatIsInTheFirstHalfOfTheStackBToTopByRotate) {
	t_stack	b;
	t_state	state;
	t_move move;
	move.from = 1;
	move.to = 0;
	ft_state_init(&state);
	ft_stack_init(&b);
	ft_stack_push(&b, 41);
	ft_stack_push(&b, 42);
	ft_stack_push(&b, 43);
	ft_stack_push(&b, 44);

	ft_move_ith_to(move, &state, &b, rb);

	ASSERT_EQ(1, state.total_ops);
	ASSERT_STREQ("rb", (char *)state.ops->content);
	ASSERT_EQ(43, ft_stack_peek(&b));

	ft_state_clear(&state);
	ft_stack_clear(&b);
}

TEST(ft_move_ith_to, itShouldMoveAnElementThatIsInTheSecondHalfOfTheStackBToTheTopByReverseRotate) {
	t_stack	b;
	t_state	state;
	t_move move;
	move.from = 3;
	move.to = 0;
	ft_state_init(&state);
	ft_stack_init(&b);
	ft_stack_push(&b, 41);
	ft_stack_push(&b, 42);
	ft_stack_push(&b, 43);
	ft_stack_push(&b, 44);

	ft_move_ith_to(move, &state, &b, rb);

	ASSERT_EQ(1, state.total_ops);
	ASSERT_STREQ("rrb", (char *)state.ops->content);
	ASSERT_EQ(41, ft_stack_peek(&b));

	ft_state_clear(&state);
	ft_stack_clear(&b);
}

TEST(ft_move_ith_to, itShouldMoveAnElementFromTopOfTheStackBToTheEndByRotate) {
	t_stack	b;
	t_state	state;
	t_move move;
	move.from = 0;
	move.to = 3;
	ft_state_init(&state);
	ft_stack_init(&b);
	ft_stack_push(&b, 41);
	ft_stack_push(&b, 42);
	ft_stack_push(&b, 43);
	ft_stack_push(&b, 44);

	ft_move_ith_to(move, &state, &b, rb);

	ASSERT_EQ(1, state.total_ops);
	ASSERT_STREQ("rb", (char *)state.ops->content);
	ASSERT_EQ(44, ft_stack_get_nth_number(&b, 4));

	ft_state_clear(&state);
	ft_stack_clear(&b);
}

