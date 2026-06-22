/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 08:05:38 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 14:19:57 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include<stdio.h>

int	convert_f(int fd, va_list args)
{
	float	x;
	int		counter;
	int		n;
	char	*str_nbr;

	counter = 0;
	x = va_arg(args, double);
	if ((long)x > INT_MAX || (long)x < INT_MIN)
		return (FAIL);
	n = (int) x;
	str_nbr = ft_itoa(n);
	if (!str_nbr)
		return (FAIL);
	counter += ft_printf_fd(fd, "%d", n);
	counter += ft_putchar_fd('.', fd);
	n = (int)((x - n) * 1000);
	if (n < 0)
		n *= -1;
	if (n % 10 == 9)
		n++;
	free(str_nbr);
	counter += ft_printf_fd(fd, "%0.2d", n / 10);
	return (counter);
}
