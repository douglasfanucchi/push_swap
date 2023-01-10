/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:57:29 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 17:21:58 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate(int *stack, int size)
{
	int	top;

	if (size == 0)
		return ;
	top = stack[0];
	ft_memmove(stack, stack + 1, (size - 1) * sizeof(int));
	stack[size - 1] = top;
}

void	ft_reverse_rotate(int *stack, int size)
{
	int	last;

	if (size == 0)
		return ;
	last = stack[size - 1];
	ft_memmove(stack + 1, stack, size * sizeof(int));
	stack[0] = last;
}

void	ft_push(int *origin, int *dest, int *size_origin, int *size_dest)
{
	int	top;

	if (*size_origin == 0)
		return ;
	top = origin[0];
	ft_memmove(origin, origin + 1, (*size_origin - 1) * sizeof(int));
	*size_origin -= 1;
	ft_memmove(dest + 1, dest, *size_dest * sizeof(int));
	dest[0] = top;
	*size_dest += 1;
}

void	ft_swap(int *stack, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}
