/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:59:42 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 23:59:42 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

static int	get_max_len(int *stack, int size)
{
	int	max_value;
	int	digits;
	int	i;

	i = 0;
	digits = 1;
	max_value = stack[0];
	while (i < size)
	{
		if (stack[i] > max_value)
			max_value = stack[i];
		i++;
	}
	while (max_value / 2)
	{
		max_value /= 2;
		digits++;
	}
	return (digits);
}

void	ft_radix(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	j;
	int	stack_size;
	int	max_len;

	stack_size = size_a;
	max_len = get_max_len(stack_a, size_a);
	i = 0;
	while (i < max_len)
	{
		j = 0;
		while (j < stack_size)
		{
			if (stack_a[0] >> i & 0b00000001)
				ft_rotate_a(stack_a, size_a);
			else
				ft_push_b(stack_a, stack_b, &size_a, &size_b);
			j++;
		}
		while (size_b)
			ft_push_a(stack_a, stack_b, &size_a, &size_b);
		i++;
	}
}
