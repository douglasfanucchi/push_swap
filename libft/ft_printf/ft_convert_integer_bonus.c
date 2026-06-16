/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_integer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:34:14 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/07 10:21:57 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	convert_u(t_printf_info *info, va_list args)
{
	char			*str_nbr;
	int				counter;
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	counter = 0;
	if (!nbr && !info->prec)
		return (width_edge_case(info));
	str_nbr = ft_utoa(nbr);
	if (!str_nbr)
		return (FAIL);
	if (!get_precision_diu(info, &str_nbr))
		return (FAIL);
	if (!get_width(info, &str_nbr))
		return (FAIL);
	counter += ft_putstr_fd(str_nbr, 1);
	free(str_nbr);
	return (counter);
}

int	convert_di(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	int		counter;
	int		nbr;

	nbr = va_arg(args, int);
	counter = 0;
	if (!nbr && !info->prec)
		return (width_edge_case(info));
	str_nbr = ft_itoa(nbr);
	if (!str_nbr)
		return (FAIL);
	if (!get_precision_diu(info, &str_nbr))
		return (FAIL);
	if (!get_width(info, &str_nbr))
		return (FAIL);
	counter += ft_putstr_fd(str_nbr, 1);
	free(str_nbr);
	return (counter);
}

int	width_edge_case(t_printf_info *info)
{
	char	*str_nbr;
	int		counter;

	counter = 0;
	if (info->width)
	{
		str_nbr = ft_strdup("");
		if (!str_nbr)
			return (FAIL);
		if (!get_width(info, &str_nbr))
			return (FAIL);
		counter += ft_putstr_fd(str_nbr, 1);
		free(str_nbr);
	}
	return (counter);
}
