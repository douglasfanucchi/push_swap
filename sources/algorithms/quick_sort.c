/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:21:44 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 21:28:23 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_quick_sort(t_item **stack, int start, int end)
{
	int		pivot;
	int		less;
	int		greater;
	t_item	*tmp;

	if (end - start <= 1)
		return ;
	pivot = end - 1;
	less = start;
	greater = start;
	while (greater < end)
	{
		if (stack[greater]->value <= stack[pivot]->value)
		{
			tmp = stack[less];
			stack[less] = stack[greater];
			stack[greater] = tmp;
			less++;
		}
		greater++;
	}
	ft_quick_sort(stack, start, less - 1);
	ft_quick_sort(stack, less, end);
}
