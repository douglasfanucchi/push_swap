/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:58:48 by dode-lim          #+#    #+#             */
/*   Updated: 2026/07/10 19:53:57 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_ith_to(t_move move, t_state *state, t_stack *stack,
	t_operations operation)
{
	int	i;
	int	size;

	size = ft_abs(move.from - move.to) + 1;
	i = 0;
	while (i < ft_min(size - 1, stack->size - size + 1))
	{
		if ((move.from < move.to && size >= stack->size / 2)
			|| (move.to < move.from && size <= stack->size / 2))
		{
			if (operation == ra)
				ft_exec_operation(state, stack, NULL, ft_rotate_a);
			else
				ft_exec_operation(state, NULL, stack, ft_rotate_b);
		}
		else
		{
			if (operation == ra)
				ft_exec_operation(state, stack, NULL, ft_reverse_rotate_a);
			else
				ft_exec_operation(state, NULL, stack, ft_reverse_rotate_b);
		}
		i++;
	}
}

t_bool	ft_is_sorted(const t_stack *stack)
{
	int		i;
	t_stack	stack_cpy;

	i = 0;
	if (stack->size < 2)
		return (TRUE);
	stack_cpy = ft_stack_copy(stack);
	while (i < stack->size - 1)
	{
		if (ft_stack_peek(&stack_cpy) > ft_stack_get_nth_number(&stack_cpy, 2))
		{
			ft_stack_clear(&stack_cpy);
			return (FALSE);
		}
		ft_stack_rotate(&stack_cpy);
		i++;
	}
	ft_stack_clear(&stack_cpy);
	return (TRUE);
}

void	ft_move_to_top(t_state *state, t_stack *stack, int index,
	t_operations op)
{
	int	sum;

	sum = 1;
	if (index <= stack->size / 2)
		sum = -1;
	while (index % stack->size)
	{
		if (sum > 0)
		{
			if (op == ra)
				ft_exec_operation(state, stack, NULL, ft_reverse_rotate_a);
			else
				ft_exec_operation(state, NULL, stack, ft_reverse_rotate_b);
		}
		else
		{
			if (op == ra)
				ft_exec_operation(state, stack, NULL, ft_rotate_a);
			else
				ft_exec_operation(state, NULL, stack, ft_rotate_b);
		}
		index += sum;
	}
}
