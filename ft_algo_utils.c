/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:58:48 by dode-lim          #+#    #+#             */
/*   Updated: 2026/07/10 18:26:18 by dode-lim         ###   ########.fr       */
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
		if ((move.from < move.to && size >= stack->size / 2) ||
			(move.to < move.from && size <= stack->size / 2))
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
