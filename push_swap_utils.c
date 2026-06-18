/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:17:21 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/18 19:29:45 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_operation_label(t_operations op)
{
	if (op == sa)
		return (ft_strdup("sa"));
	else if (op == sb)
		return (ft_strdup("sb"));
	else if (op == ss)
		return (ft_strdup("ss"));
	else if (op == pa)
		return (ft_strdup("pa"));
	else if (op == pb)
		return (ft_strdup("pb"));
	else if (op == ra)
		return (ft_strdup("ra"));
	else if (op == rb)
		return (ft_strdup("rb"));
	else if (op == rr)
		return (ft_strdup("rr"));
	else if (op == rra)
		return (ft_strdup("rra"));
	else if (op == rrb)
		return (ft_strdup("rrb"));
	else if (op == rrr)
		return (ft_strdup("rrr"));
	return (NULL);
}
