/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:28:02 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/29 21:28:03 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operations	ft_rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size < 2)
		return (ra);
	ft_stack_rotate(a);
	return (ra);
}

t_operations	ft_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->size < 2)
		return (rb);
	ft_stack_rotate(b);
	return (rb);
}

t_operations	ft_rotate_rr(t_stack *a, t_stack *b)
{
	ft_rotate_a(a, NULL);
	ft_rotate_b(NULL, b);
	return (rr);
}
