/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:29:29 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 09:26:27 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_of_digits(int nbr);
static void	get_digits(int nbr, int digit, char nbr_to_print[17]);

size_t	ft_putnbr_fd(int nbr, int fd)
{
	int		digit;
	char	nbr_to_print[17];
	size_t	counter;

	digit = number_of_digits(nbr);
	counter = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		counter++;
	}
	nbr_to_print[digit] = '\0';
	if (!nbr)
		nbr_to_print[0] = '0';
	get_digits(nbr, digit, nbr_to_print);
	ft_putstr_fd(nbr_to_print, fd);
	return (counter + ft_strlen(nbr_to_print));
}

static int	number_of_digits(int nbr)
{
	int	digits;

	digits = 1;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

static void	get_digits(int nbr, int digit, char nbr_to_print[17])
{
	while (nbr)
	{
		digit--;
		if (nbr >= 0)
			nbr_to_print[digit] = nbr % 10 + '0';
		else
			nbr_to_print[digit] = (nbr % 10) * (-1) + '0';
		nbr = nbr / 10;
	}
}
