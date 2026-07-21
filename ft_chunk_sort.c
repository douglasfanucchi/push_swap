/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanucchi <fanucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:43:35 by dode-lim          #+#    #+#             */
/*   Updated: 2026/07/20 22:13:12 by fanucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_reversed(t_stack *stack, int size)
{
	t_bool	is_reverse_sorted;
	t_stack	cpy;
	int		i;

	if (stack->size == 1 || size < 2)
		return (TRUE);
	cpy = ft_stack_copy(stack);
	is_reverse_sorted = TRUE;
	i = 0;
	while (i < size - 1)
	{
		if (ft_stack_peek(&cpy) < ft_stack_get_nth_number(&cpy, 2))
			is_reverse_sorted = FALSE;
		ft_stack_rotate(&cpy);
		i++;
	}
	ft_stack_clear(&cpy);
	return (is_reverse_sorted);
}

static int	ft_get_pos(t_stack *a, int substack_size, int min, int top)
{
	t_substack	substack;
	int			pos;

	substack.start = ft_stack_find(a, min, ft_eq);
	if (substack.start == 0)
		substack.size = substack_size;
	else
		substack.size = a->size - substack.start;
	pos = ft_stack_find_offset(a, substack, top, ft_gt);
	pos += substack.start;
	if (pos == substack.start - 1 && substack.start != 0)
	{
		substack.start = 0;
		substack.size = substack_size - substack.size;
		pos = ft_stack_find_offset(a, substack, top, ft_gt);
		pos += substack.start;
	}
	if (pos == substack.start - 1)
		pos = substack.size - 1;
	return (pos);
}

void	ft_reverse_insertion_sort_substack(t_stack *a, t_stack *b,
	t_state *state, int size)
{
	int			pos;
	int			min;
	int			i;

	if (is_reversed(b, size))
		return ;
	ft_exec_operation(state, a, b, ft_push_a);
	min = ft_stack_peek(a);
	i = 1;
	while (i < size)
	{
		pos = ft_get_pos(a, i, min, ft_stack_peek(b));
		if (ft_stack_peek(b) < min)
			min = ft_stack_peek(b);
		ft_move_to_top(state, a, pos, ra);
		ft_exec_operation(state, a, b, ft_push_a);
		if (ft_stack_peek(a) > ft_stack_get_nth_number(a, 2))
			ft_exec_operation(state, a, b, ft_swap_a);
		i++;
	}
	ft_move_to_top(state, a, ft_stack_find(a, min, ft_eq), ra);
	while (i-- > 0)
		ft_exec_operation(state, a, b, ft_push_b);
}

t_state	ft_chunk_sort(t_stack *a, t_stack *b)
{
	t_state	state;
	int		i;
	int		_sqrt;
	int		range[2];
	t_stack	*stacks[2];

	ft_state_init(&state);
	_sqrt = ft_sqrt(a->size);
	i = -1;
	range[0] = 0;
	stacks[0] = a;
	stacks[1] = b;
	while (++i < _sqrt)
	{
		range[1] = range[0] + _sqrt - 1;
		ft_push_range(range, stacks, &state, pb);
		ft_reverse_insertion_sort_substack(a, b, &state, _sqrt);
		range[0] += _sqrt;
	}
	while (a->size)
		ft_exec_operation(&state, a, b, ft_push_b);
	ft_reverse_insertion_sort_substack(a, b, &state, b->size - (_sqrt * _sqrt));
	while (b->size)
		ft_exec_operation(&state, a, b, ft_push_a);
	return (state);
}
