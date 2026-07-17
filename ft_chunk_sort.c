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
