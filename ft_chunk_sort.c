/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:43:35 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/30 12:43:35 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_arr	get_numbers(int *range, t_stack *stack)
{
	t_arr	numbers;
	int		i;

	numbers.elements = malloc(sizeof(int) * (range[1] - range[0] + 1));
	numbers.len = 0;
	i = 0;
	while (i < stack->size)
	{
		if (ft_stack_peek(stack) >= range[0]
			&& ft_stack_peek(stack) <= range[1])
		{	
			((int *)numbers.elements)[numbers.len] = ft_stack_peek(stack);
			numbers.len++;
		}
		ft_stack_rotate(stack);
		i++;
	}
	return (numbers);
}

int	ft_push_range(int *range, t_stack **stacks, t_state *state,
	t_operations op)
{
	t_arr			numbers;
	int				i;
	t_operations	rotate;
	int				pos;

	rotate = ra;
	if (op == pa)
		rotate = rb;
	numbers = get_numbers(range, stacks[0]);
	i = 0;
	while (i < numbers.len)
	{
		pos = ft_stack_find(stacks[0], ((int *)numbers.elements)[i], ft_eq);
		ft_move_to_top(state, stacks[0], pos, rotate);
		if (op == pb)
			ft_exec_operation(state, stacks[0], stacks[1], ft_push_b);
		else
			ft_exec_operation(state, stacks[1], stacks[0], ft_push_a);
		i++;
	}
	free(numbers.elements);
	return (numbers.len);
}

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

void	ft_reverse_insertion_sort_substack(t_stack *a, t_stack *b,
	t_state *state, int size)
{
	int			pos;
	t_substack	substack;
	int			min;

	if (is_reversed(b, size))
		return ;
	ft_exec_operation(state, a, b, ft_push_a);
	substack.start = 0;
	min = ft_stack_peek(a);
	substack.size = 0;
	while (++substack.size < size)
	{
		pos = ft_stack_find_offset(a, substack, ft_stack_peek(b), ft_gt);
		if (ft_stack_peek(b) < min)
			min = ft_stack_peek(b);
		if (pos == -1)
			pos = substack.size - 1;
		ft_move_to_top(state, a, pos, ra);
		ft_exec_operation(state, a, b, ft_push_a);
		if (ft_stack_peek(a) > ft_stack_get_nth_number(a, 2))
			ft_exec_operation(state, a, b, ft_swap_a);
		ft_move_to_top(state, a, ft_stack_find(a, min, ft_eq), ra);
	}
	while (substack.size-- > 0)
		ft_exec_operation(state, a, b, ft_push_b);
}
