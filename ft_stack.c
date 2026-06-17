/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:15:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/17 17:49:35 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

int		ft_stack_push(t_stack *stack, int n)
{
	t_dlist	*tmp;

	tmp = stack->head;
	ft_dlstadd_front(&stack->head, ft_dlstnew(n));
	if (tmp == stack->head)
		return (stack->size);
	stack->size++;
	return (stack->size);
}

int		ft_stack_pop(t_stack *stack)
{
	t_dlist	*node;

	node = ft_dlst_pop(&stack->head);
	free(node);
	stack->size--;
	return (stack->size);
}
