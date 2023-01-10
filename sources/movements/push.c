/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:55:51 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 17:58:04 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_push_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	ft_push(stack_b, stack_a, size_b, size_a);
	ft_putstr("pa\n");
}

void	ft_push_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	ft_push(stack_a, stack_b, size_a, size_b);
	ft_putstr("pb\n");
}
