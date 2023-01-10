/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:51 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 17:27:35 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_a(int *stack_a, int size)
{
	if (size < 2)
		return ;
	ft_swap(stack_a, size);
	ft_putstr("sa\n");
}

void	swap_b(int *stack_b, int size)
{
	if (size < 2)
		return ;
	ft_swap(stack_b, size);
	ft_putstr("sb\n");
}
