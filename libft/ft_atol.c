/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:55:57 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/02 17:04:38 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_isdigit ft_isspace

long	ft_atol(const char *nptr)
{
	long	sign;
	long	n;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = (-1);
		nptr++;
	}
	n = 0;
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + sign * (*nptr - '0');
		nptr++;
	}
	return (n);
}
