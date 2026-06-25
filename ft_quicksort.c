/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:21:04 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/25 15:51:52 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_less_than_int(void *elements, int i, int j)
{
	int	a;
	int	b;
	int	*numbers;

	numbers = (int *)elements;
	a = numbers[i];
	b = numbers[j];
	return (a < b);
}

void	ft_swap_int(void *elements, int i, int j)
{
	int	tmp;
	int	*numbers;

	numbers = (int *)elements;
	tmp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = tmp;
}

t_bool	ft_less_than_pair(void *elements, int i, int j)
{
	int	**pairs;

	pairs = (int **)elements;
	return (pairs[i][1] < pairs[j][1]);
}


void	ft_swap_pair(void *elements, int i, int j)
{
	int	**pairs;
	int	*tmp_pair;

	pairs = (int **)elements;
	tmp_pair = pairs[i];
	pairs[i] = pairs[j];
	pairs[j] = tmp_pair;
}

void	ft_quicksort(t_arr arr, size_t bytes, t_bool (*less_than)(), void (*swap)())
{
	t_arr	arr_left;
	t_arr	arr_right;
	int		pivot;
	int		l;
	int		r;

	if (arr.len < 2)
		return ;
	pivot = arr.len - 1;
	l = 0;
	r = 0;
	while (r < arr.len)
	{
		if (less_than(arr.elements, r, pivot))
			swap(arr.elements, r, l++);
		r++;
	}
	swap(arr.elements, pivot, l);
	arr_left.len = l;
	arr_left.elements = arr.elements;
	arr_right.len = arr.len - l - 1;
	arr_right.elements = arr.elements + (l + 1) * bytes;
	ft_quicksort(arr_left, bytes, less_than, swap);
	ft_quicksort(arr_right, bytes, less_than, swap);
}
