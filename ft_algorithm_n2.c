/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_n2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:21:15 by gucoelho          #+#    #+#             */
/*   Updated: 2026/07/22 15:04:09 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_pos(t_stack *b, int n, int *pos)
{
	t_arr	lt_arr;
	int		i;

	lt_arr.len = 0;
	lt_arr.elements = malloc(sizeof(int *) * b->size);
	i = -1;
	*pos = -1;
	while (++i < b->size)
	{
		if (n > ft_stack_peek(b))
		{
			((int **)lt_arr.elements)[lt_arr.len] = malloc(sizeof(int) * 2);
			((int **)lt_arr.elements)[lt_arr.len][0] = i;
			((int **)lt_arr.elements)[lt_arr.len++][1] = ft_stack_peek(b);
		}
		ft_stack_rotate(b);
	}
	ft_quicksort(lt_arr, sizeof(int *), ft_less_than_pair, ft_swap_pair);
	if (lt_arr.len)
		*pos = ((int **)lt_arr.elements)[lt_arr.len - 1][0];
	i = 0;
	while (i < lt_arr.len)
		free(((int **)lt_arr.elements)[i++]);
	free(lt_arr.elements);
}

t_state	ft_insertion_sort(t_stack *a, t_stack *b)
{
	t_state	state;
	int		pos;
	int		max;

	ft_state_init(&state);
	ft_exec_operation(&state, a, b, ft_push_b);
	max = ft_stack_peek(b);
	while (a->size)
	{
		ft_set_pos(b, ft_stack_peek(a), &pos);
		if (pos == -1)
			pos = ft_stack_find(b, max, ft_eq);
		ft_move_to_top(&state, b, pos, rb);
		ft_exec_operation(&state, a, b, ft_push_b);
		if (ft_stack_peek(b) > max)
			max = ft_stack_peek(b);
	}
	pos = ft_stack_find(b, b->size - 1, ft_eq);
	ft_move_to_top(&state, b, pos, rb);
	while (b->size)
		ft_exec_operation(&state, a, b, ft_push_a);
	return (state);
}
