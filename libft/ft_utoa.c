/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:29:35 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/05 11:29:35 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_digits(unsigned int n);

char	*ft_utoa(unsigned int n)
{
	char	*s;
	int		nd;

	nd = number_digits(n);
	s = (char *) malloc(nd + 1);
	if (s == NULL)
		return (NULL);
	s[nd--] = '\0';
	if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		s[nd] = n % 10 + 48;
		n = n / 10;
		nd--;
	}
	return (s);
}

static int	number_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
