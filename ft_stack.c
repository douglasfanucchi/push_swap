/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:15:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/25 18:56:06 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	stack->arr = NULL;
	stack->size = 0;
	stack->arr_size = 0;
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
	free(stack->arr);
	stack->arr = NULL;
	stack->arr_size = 0;
	stack->size = 0;
}
