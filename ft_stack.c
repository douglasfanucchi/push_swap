/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:15:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/30 14:57:35 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

t_stack	ft_int_arr_to_normalized_stack(t_arr *arr)
{
	t_arr	normalized;
	int		i;
	t_stack	stack;

	i = 0;
	normalized = ft_normalize_int_arr(arr);
	ft_stack_init(&stack);
	while (i < normalized.len)
	{
		ft_stack_push(&stack, ((int *)normalized.elements)[i]);
		ft_stack_rotate(&stack);
		i++;
	}
	free(normalized.elements);
	return (stack);
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
