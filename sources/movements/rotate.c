/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:28:08 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 17:54:26 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate_a(int *stack, int size)
{
	ft_rotate(stack, size);
	ft_putstr("ra\n");
}

void	ft_rotate_b(int *stack, int size)
{
	ft_rotate(stack, size);
	ft_putstr("rb\n");
}

void	ft_rotate_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
	ft_rotate(stack_a, size_a);
	ft_rotate(stack_b, size_b);
	ft_putstr("rr\n");
}
