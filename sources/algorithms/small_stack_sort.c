/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:07:11 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/12 20:36:44 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_3_elements(int *stack, int size)
{
	if (stack[1] > stack[0] && stack[1] > stack[2])
		ft_reverse_rotate_a(stack, size);
	else if (stack[0] > stack[1] && stack[0] > stack[2])
		ft_rotate_a(stack, size);
	if (stack[0] > stack[1])
		ft_swap_a(stack, size);
}

static void	rewind_stack(int *stack, int size, int rotated)
{
	if (stack[0] == size - 1)
	{
		ft_rotate_a(stack, size);
		return ;
	}
	if (stack[0] == size - 2)
	{
		ft_rotate_a(stack, size);
		ft_rotate_a(stack, size);
		return ;
	}
	while (rotated)
	{
		ft_reverse_rotate_a(stack, size);
		rotated--;
	}
}

void	ft_small_stack_sort(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	rotate_a;

	if (size_a == 2 && stack_a[0] > stack_a[1])
		return (ft_swap_a(stack_a, size_a));
	if (size_a == 3)
		return (sort_3_elements(stack_a, size_a));
	rotate_a = 0;
	ft_push_b(stack_a, stack_b, &size_a, &size_b);
	if (size_a > 3)
		ft_push_b(stack_a, stack_b, &size_a, &size_b);
	sort_3_elements(stack_a, size_a);
	if (size_b > 1 && stack_b[0] > stack_b[1])
		ft_swap_b(stack_b, size_b);
	while (1)
	{
		if (stack_b[0] < stack_a[0] || rotate_a == size_a)
			ft_push_a(stack_a, stack_b, &size_a, &size_b);
		if (!size_b)
			break ;
		ft_rotate_a(stack_a, size_a);
		rotate_a++;
	}
	rewind_stack(stack_a, size_a, rotate_a);
}
