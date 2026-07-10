/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:06:30 by dode-lim          #+#    #+#             */
/*   Updated: 2026/07/10 15:33:47 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_find_offset(const t_stack *stack,
					t_substack substack, int n, t_bool (*f)(int, int))
{
	int		i;
	t_dlist	*node;
	t_stack	stack_2;

	i = 0;
	stack_2.size = substack.size;
	node = stack->head;
	while (i < substack.start)
	{
		i++;
		node = node->next;
	}
	stack_2.head = node;
	return (ft_stack_find(&stack_2, n, f));
}
