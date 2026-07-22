/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_edge_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:14:02 by dode-lim          #+#    #+#             */
/*   Updated: 2026/07/22 17:11:42 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_tiny(t_state *state, t_stack *a)
{
	if (ft_is_sorted(a))
		return ;
	if (ft_stack_peek(a) == 0 && ft_stack_get_nth_number(a, 2) == 2)
	{
		ft_exec_operation(state, a, NULL, ft_reverse_rotate_a);
		ft_exec_operation(state, a, NULL, ft_swap_a);
	}
	else if (ft_stack_peek(a) == 1 && ft_stack_get_nth_number(a, 2) == 0)
		ft_exec_operation(state, a, NULL, ft_swap_a);
	else if (ft_stack_peek(a) == 1 && ft_stack_get_nth_number(a, 2) == 2)
		ft_exec_operation(state, a, NULL, ft_reverse_rotate_a);
	else if (ft_stack_peek(a) == 2 && ft_stack_get_nth_number(a, 2) == 0)
		ft_exec_operation(state, a, NULL, ft_rotate_a);
	else if (ft_stack_peek(a) == 2 && ft_stack_get_nth_number(a, 2) == 1)
	{
		ft_exec_operation(state, a, NULL, ft_rotate_a);
		ft_exec_operation(state, a, NULL, ft_swap_a);
	}
}

t_state	ft_sort_small(const t_stack *stack)
{
	int		i;
	t_state	state;
	t_stack	a;
	t_stack	b;

	ft_state_init(&state);
	a = ft_stack_copy(stack);
	ft_stack_init(&b);
	i = 0;
	while (i < stack->size - 3)
	{
		ft_move_to_top(&state, &a,
			ft_stack_find(&a, a.size - 1, ft_eq), ra);
		ft_exec_operation(&state, &a, &b, ft_push_b);
		i++;
	}
	ft_sort_tiny(&state, &a);
	while (b.size)
	{
		ft_exec_operation(&state, &a, &b, ft_push_a);
		ft_exec_operation(&state, &a, &b, ft_rotate_a);
	}
	ft_stack_clear(&a);
	return (state);
}
