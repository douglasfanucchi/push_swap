/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:15:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/30 17:23:05 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

void	ft_stack_clear(t_stack *stack)
{
	ft_dlstclear(&stack->head);
}

int	ft_stack_get_nth_number(const t_stack *stack, int n)
{
	t_dlist	*node;
	int		i;

	i = 0;
	node = stack->head;
	while (i < n - 1)
	{
		node = node->next;
		i++;
	}
	return (node->n);
}

int	ft_stack_find(const t_stack *stack, int n, t_bool (*f)(int, int))
{
	t_dlist	*node;
	int		i;

	i = 0;
	node = stack->head;
	while (!f(n, node->n) && i < stack->size)
	{
		node = node->next;
		i++;
	}
	if (i == stack->size)
		return (-1);
	return (i);
}

t_stack	ft_stack_copy(const t_stack *stack)
{
	t_dlist	*node;
	t_stack	copy;
	int		i;

	ft_stack_init(&copy);
	node = stack->head;
	i = 0;
	while (i < stack->size)
	{
		ft_stack_push(&copy, node->n);
		ft_stack_rotate(&copy);
		node = node->next;
		i++;
	}
	return (copy);
}
