/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:29:30 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/05 11:29:30 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	max;
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size == 0 || len_d >= size)
		return (len_s + size);
	max = size - len_d - 1;
	index = 0;
	while (src[index] != '\0' && index < max && len_d < size)
	{
		dst[len_d + index] = src[index];
		index++;
	}
	dst[len_d + index] = '\0';
	return (len_s + len_d);
}
