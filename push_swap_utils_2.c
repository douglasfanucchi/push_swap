/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:27:14 by dode-lim          #+#    #+#             */
/*   Updated: 2026/07/10 17:50:28 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_bool	ft_eq(int a, int b)
{
	return (a == b);
}

t_bool	ft_gt(int a, int b)
{
	return (b > a);
}
