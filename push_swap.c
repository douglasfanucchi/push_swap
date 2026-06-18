/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:08:07 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/18 19:12:16 by dode-lim         ###   ########.fr       */
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
	if (op == sa)
		str_op = ft_strdup("sa");
	else if (op == sb)
		str_op = ft_strdup("sb");
	else if (op == ss)
		str_op = ft_strdup("ss");
	else if (op == pa)
		str_op = ft_strdup("pa");
	else if (op == pb)
		str_op = ft_strdup("pb");
	else if (op == ra)
		str_op = ft_strdup("ra");
	else if (op == rb)
		str_op = ft_strdup("rb");
	else if (op == rr)
		str_op = ft_strdup("rr");
	else if (op == rra)
		str_op = ft_strdup("rra");
	else if (op == rrb)
		str_op = ft_strdup("rrb");
	else if (op == rrr)
		str_op = ft_strdup("rrr");
	state->count_ops[op]++;
	state->total_ops++;
	ft_lstadd_front(&state->ops, ft_lstnew(str_op));
}
