/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:03:10 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 18:15:27 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_reverse_rotate_a(int *stack, int size)
{
	ft_reverse_rotate(stack, size);
	ft_putstr("rra\n");
}

void	ft_reverse_rotate_b(int *stack, int size)
{
	ft_reverse_rotate(stack, size);
	ft_putstr("rrb\n");
}

void	ft_reverse_rotate_both(int *stack_a, int *stack_b, int size_a,
								int size_b)
{
	ft_reverse_rotate(stack_a, size_a);
	ft_reverse_rotate(stack_b, size_b);
	ft_putstr("rrr\n");
}
