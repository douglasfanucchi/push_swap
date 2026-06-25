/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:06:05 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/25 18:39:22 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	ft_normalize_int_arr(t_arr arr)
{
	int		i;
	t_arr	result;
	t_arr	pairs;

	result.len = arr.len;
	result.elements = malloc(sizeof(int) * result.len);
	ft_memmove(result.elements, arr.elements, sizeof(int) * (result.len));
	pairs.len = result.len;
	pairs.elements = malloc(sizeof(int *) * (result.len));
	i = -1;
	while (++i < pairs.len)
	{
		((int **)pairs.elements)[i] = malloc(sizeof(int) * 2);
		((int **)pairs.elements)[i][0] = i;
		((int **)pairs.elements)[i][1] = ((int *)result.elements)[i];
	}
	ft_quicksort(pairs, sizeof(int *), ft_less_than_pair, ft_swap_pair);
	i = -1;
	while (++i < pairs.len)
		((int *)result.elements)[((int **)pairs.elements)[i][0]] = i;
	i = 0;
	while (i < pairs.len)
		free(((int **)pairs.elements)[i++]);
	free(pairs.elements);
	return (result);
}
