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

t_bool	ft_exec_operation(t_state *state, t_stack *stack_1, t_stack *stack_2,
			t_operations (*f)(t_stack *stack_1, t_stack *stack_2))
{
	t_operations	op;

	op = f(stack_1, stack_2);
	return (ft_state_update(state, op));
}

void	ft_program_print(const t_program *program)
{
	double	disorder_percentage;
	int		count_ops[11];
	char	*strategy_label;

	strategy_label = "Adaptative";
	if (program->strategy == simple)
		strategy_label = "Simple";
	if (program->strategy == medium)
		strategy_label = "Medium";
	if (program->strategy == complex)
		strategy_label = "Complex";
	disorder_percentage = program->disorder * 100;
	ft_memmove(count_ops, program->state.count_ops, sizeof(int) * 11);
	ft_printf_fd(2, "[bench] disorder:  %f%%\n", disorder_percentage);
	ft_printf_fd(2, "[bench] strategy:  %s / %s\n", strategy_label,
		program->state.complexity);
	ft_printf_fd(2, "[bench] total_ops:  %d\n", program->state.total_ops);
	ft_printf_fd(2, "[bench] sa:  %d  sb:  %d  ss:  %d  ",
		count_ops[sa], count_ops[sb], count_ops[ss]);
	ft_printf_fd(2, "pa:  %d  pb:  %d\n", count_ops[pa], count_ops[pb]);
	ft_printf_fd(2, "[bench] ra:  %d  rb:  %d  rr:  %d  ", count_ops[ra],
		count_ops[rb], count_ops[rr]);
	ft_printf_fd(2, "rra:  %d  rrb:  %d  rrr:  %d\n", count_ops[rra],
		count_ops[rrb], count_ops[rrr]);
}
