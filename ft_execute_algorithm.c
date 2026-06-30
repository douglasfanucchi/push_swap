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

static t_state	exec(t_state (*algorithm)(t_stack *, t_stack *),
	t_stack *a, t_stack *b)
{
	return (algorithm(a, b));
}

t_state	ft_execute_algorithm(t_strategy strategy, double disorder,
		const t_stack *a)
{
	t_list	*algorithms[3];
	t_state	state;
	t_stack	a_cpy;
	t_stack	b;

	(void)strategy;
	a_cpy = ft_stack_copy(a);
	ft_stack_init(&b);
	algorithms[complex] = NULL;
	ft_lstadd_back(&algorithms[complex], ft_lstnew(ft_bubble_sort));
	state = exec(algorithms[complex]->content, &a_cpy, &b);
	if (disorder < 0.5)
		state.complexity = ft_strdup("O(n√n)");
	else
		state.complexity = ft_strdup("O(nlogn)");
	free(algorithms[complex]);
	ft_stack_clear(&a_cpy);
	return (state);
}
