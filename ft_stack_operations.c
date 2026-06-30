/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:03:47 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/29 21:29:23 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_push(t_stack *stack, int n)
{
	t_dlist	*tmp;

	tmp = stack->head;
	ft_dlstadd_front(&stack->head, ft_dlstnew(n));
	if (tmp == stack->head)
		return (stack->size);
	stack->size++;
	return (stack->size);
}

int	ft_stack_pop(t_stack *stack)
{
	t_dlist	*node;

	node = ft_dlst_pop(&stack->head);
	free(node);
	stack->size--;
	return (stack->size);
}

int	ft_stack_peek(const t_stack *stack)
{
	return (stack->head->n);
}

void	ft_stack_rotate(t_stack *stack)
{
	stack->head = stack->head->next;
}

void	ft_stack_reverse_rotate(t_stack *stack)
{
	stack->head = stack->head->prev;
}
