/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:34:35 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/07 10:17:49 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	convert_p(int fd, t_printf_info *info, va_list args)
{
	int					counter;
	char				*str;
	unsigned long int	hex_nbr;

	counter = 0;
	hex_nbr = va_arg(args, unsigned long int);
	if (!hex_nbr)
		str = ft_strdup("(nil)");
	else
	{
		str = ft_litoa_base(hex_nbr, HEXBASELOW);
		if (!str)
			return (FAIL);
		str = ft_strjoin_free("0x", &str);
	}
	if (!str)
		return (FAIL);
	if (!get_width(info, &str))
		return (FAIL);
	counter += ft_putstr_fd(str, fd);
	free (str);
	return (counter);
}
