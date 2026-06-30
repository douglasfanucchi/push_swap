/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:31:36 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/29 21:39:55 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_operation(t_stack *stack)
{
	int	first;
	int	second;

	if (stack->size < 2)
		return ;
	first = ft_stack_peek(stack);
	ft_stack_pop(stack);
	second = ft_stack_peek(stack);
	ft_stack_pop(stack);
	ft_stack_push(stack, first);
	ft_stack_push(stack, second);
}

t_operations	ft_swap_a(t_stack *a, t_stack *b)
{
	(void)b;
	ft_swap_operation(a);
	return (sa);
}

t_operations	ft_swap_b(t_stack *a, t_stack *b)
{
	(void)a;
	ft_swap_operation(b);
	return (sb);
}

t_operations	ft_swap_ss(t_stack *a, t_stack *b)
{
	ft_swap_a(a, NULL);
	ft_swap_b(NULL, b);
	return (ss);
}
