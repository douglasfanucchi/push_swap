/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_n2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:21:15 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/30 16:46:04 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state	ft_bubble_sort(t_stack *a, t_stack *b)
{
	static t_state	state;
	t_bool			sorted;

	while (TRUE)
	{
		sorted = TRUE;
		while (a->size)
		{
			if (a->size > 1 && a->head->n > a->head->next->n)
			{
				sorted = FALSE;
				ft_exec_operation(&state, a, b, ft_swap_a);
			}
			ft_exec_operation(&state, a, b, ft_push_b);
		}
		while (b->size)
		{
			if (b->size > 1 && b->head->n < b->head->next->n)
				ft_exec_operation(&state, a, b, ft_swap_b);
			ft_exec_operation(&state, a, b, ft_push_a);
		}
		if (sorted)
			break ;
	}
	return (state);
}
