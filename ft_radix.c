/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:52:35 by dode-lim          #+#    #+#             */
/*   Updated: 2026/07/23 15:52:35 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_bits(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n >>= 1;
	}
	return (i);
}

t_state	ft_radix_sort(t_stack *a, t_stack *b)
{
	t_state	state;
	int		bits_size;
	int		i;
	int		j;
	int		size;

	ft_state_init(&state);
	bits_size = ft_count_bits(a->size - 1);
	i = -1;
	size = a->size;
	while (++i < bits_size)
	{
		j = 0;
		while (j < size)
		{
			if ((ft_stack_peek(a) >> i) & 1)
				ft_exec_operation(&state, a, b, ft_rotate_a);
			else
				ft_exec_operation(&state, a, b, ft_push_b);
			j++;
		}
		while (b->size)
			ft_exec_operation(&state, a, b, ft_push_a);
	}
	return (state);
}
