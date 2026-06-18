/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:08:07 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/18 19:42:05 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_operation(t_state *state, t_stack *stack_1, t_stack *stack_2,
			t_operations (*f)(t_stack *stack_1, t_stack *stack_2))
{
	t_operations	op;
	char			*str_op;

	str_op = NULL;
	op = f(stack_1, stack_2);
	str_op = ft_get_operation_label(op);
	if (!str_op)
		return ;
	state->count_ops[op]++;
	state->total_ops++;
	ft_lstadd_front(&state->ops, ft_lstnew(str_op));
}
