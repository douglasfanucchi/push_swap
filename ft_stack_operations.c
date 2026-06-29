/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:03:47 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/18 16:29:12 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int		ft_stack_push(t_stack *stack, int n)
{
	int	*tmp;

	if (!stack->arr)
	{
		stack->arr = malloc(sizeof(int));
		stack->arr_size = 1;
		stack->size = 1;
		stack->arr[0] = n;
		return (stack->size);
	}
	if (stack->size == stack->arr_size) {
		tmp = malloc(sizeof(int) * 2 * stack->size);
		ft_memmove(tmp + 1, stack->arr, sizeof(int) * stack->size);
		tmp[0] = n;
		stack->size++;
		stack->arr_size *= 2;
		free(stack->arr);
		stack->arr = tmp;
		return (stack->size);
	}
	ft_memmove(stack->arr + 1, stack->arr, sizeof(int) * stack->size);
	stack->arr[0] = n;
	stack->size++;
	return (stack->size);
}

int		ft_stack_pop(t_stack *stack)
{
	stack->size--;
	if (!stack->size)
	{
		ft_stack_clear(stack);
		return (0);
	}
	ft_memmove(stack->arr, stack->arr + 1, sizeof(int) * stack->size);
	return (stack->size);
}

int	ft_stack_peek(const t_stack *stack)
{
	return (stack->arr[0]);
}

void	ft_stack_rotate(t_stack *stack)
{
	int	top;

	top = ft_stack_peek(stack);
	ft_memmove(stack->arr, stack->arr + 1, (stack->size - 1) * sizeof(int));
	stack->arr[stack->size - 1] = top;
}

void	ft_stack_reverse_rotate(t_stack *stack)
{
	int	bottom;

	bottom = stack->arr[stack->size - 1];
	ft_memmove(stack->arr + 1, stack->arr, sizeof(int) * (stack->size - 1));
	stack->arr[0] = bottom;
}
