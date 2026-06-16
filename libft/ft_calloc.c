/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:26:49 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/05 11:26:51 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;
	size_t	alloc_size;

	buff = NULL;
	if (size == 0 || nmemb == 0 || size > INT_MAX / nmemb)
		return (NULL);
	alloc_size = nmemb * size;
	buff = malloc(alloc_size);
	if (!buff)
		return (NULL);
	return (ft_memset(buff, '\0', alloc_size));
}
