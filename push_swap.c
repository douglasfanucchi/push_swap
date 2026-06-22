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

	op = f(stack_1, stack_2);
	ft_state_update(state, op);
}
