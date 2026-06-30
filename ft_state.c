/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:29:42 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/29 21:31:12 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_state_init(t_state *state)
{
	ft_bzero(state, sizeof(t_state));
}

int	ft_state_print(const t_state *state)
{
	t_list	*ptr;
	int		size;

	ptr = state->ops;
	size = 0;
	while (ptr)
	{
		size += ft_printf_fd(1, "%s\n", (char *)ptr->content);
		ptr = ptr->next;
	}
	return (size);
}

int	ft_state_get_operation_count(const t_state *state, t_operations op)
{
	return (state->count_ops[op]);
}

t_bool	ft_state_update(t_state *state, t_operations op)
{
	char	*label;
	t_list	*node;

	label = ft_get_operation_label(op);
	if (!label)
		return (FALSE);
	node = ft_lstnew(label);
	if (!node)
		return (FALSE);
	ft_lstadd_back(&state->ops, node);
	state->count_ops[op]++;
	state->total_ops++;
	return (TRUE);
}

void	ft_state_clear(t_state *state)
{
	ft_lstclear(&state->ops, free);
	ft_state_init(state);
}
