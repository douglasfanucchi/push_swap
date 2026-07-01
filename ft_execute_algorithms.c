/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:31:35 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/30 18:58:35 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialize_algorithms(t_list *algorithms[3])
{
	algorithms[simple] = NULL;
	algorithms[medium] = NULL;
	algorithms[complex] = NULL;
	ft_lstadd_back(&algorithms[simple], ft_lstnew(ft_bubble_sort));
	ft_lstadd_back(&algorithms[medium], ft_lstnew(ft_bubble_sort));
	ft_lstadd_back(&algorithms[complex], ft_lstnew(ft_bubble_sort));
}

static t_state	exec(t_state (*algorithm)(t_stack *, t_stack *), t_stack *a)
{
	t_stack	b;

	ft_stack_init(&b);
	return (algorithm(a, &b));
}

static t_state	exec_algorithms(t_list *algorithms, const t_stack *a)
{
	t_state	state;
	t_state	tmp;
	t_stack	a_cpy;

	ft_state_init(&state);
	while (algorithms)
	{
		a_cpy = ft_stack_copy(a);
		tmp = exec(algorithms->content, &a_cpy);
		if (!state.total_ops || tmp.total_ops < state.total_ops)
		{
			ft_state_clear(&state);
			state = tmp;
		}
		ft_stack_clear(&a_cpy);
		algorithms = algorithms->next;
	}
	return (state);
}

static void	ft_do_nothing(void *f)
{
	(void)f;
}

t_state	ft_execute_algorithms(t_strategy strategy, double disorder,
		const t_stack *a)
{
	t_list	*algorithms[3];
	t_state	state;

	ft_initialize_algorithms(algorithms);
	if ((strategy == adaptative && disorder < 0.2) || strategy == simple)
	{
		state = exec_algorithms(algorithms[simple], a);
		state.complexity = ft_strdup("O(n²)");
	}
	else if ((strategy == adaptative && disorder < 0.5) || strategy == medium)
	{
		state = exec_algorithms(algorithms[medium], a);
		state.complexity = ft_strdup("O(n√n)");
	}
	else
	{
		state = exec_algorithms(algorithms[complex], a);
		state.complexity = ft_strdup("O(nlogn)");
	}
	ft_lstclear(&algorithms[simple], ft_do_nothing);
	ft_lstclear(&algorithms[medium], ft_do_nothing);
	ft_lstclear(&algorithms[complex], ft_do_nothing);
	return (state);
}
