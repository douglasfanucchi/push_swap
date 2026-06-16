/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:27:31 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 10:11:06 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // size_t

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			j;
	unsigned char	tmp;

	j = 0;
	if ((dest > src && (size_t)(dest - src) < n))
	{
		while (j < n)
		{
			tmp = ((t_byte_ptr)dest)[j];
			((t_byte_ptr)dest)[j] = ((t_byte_ptr)src)[0];
			((t_byte_ptr)src)[0] = tmp;
			j++;
		}
	}
	else
	{
		while (j < n)
		{
			((t_byte_ptr)dest)[j] = ((t_byte_ptr)src)[j];
			j++;
		}
	}
	return (dest);
}
