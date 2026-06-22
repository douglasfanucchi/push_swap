/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:33:27 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 10:02:18 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	add_prefix(unsigned int nbr, char **str, t_printf_info *info);
static int	prefix_and_width(unsigned int nbr, char **str, t_printf_info *info);

int	convert_x(int fd, t_printf_info *info, va_list args)
{
	unsigned int	nbr;
	char			*str;
	int				counter;

	counter = 0;
	nbr = va_arg(args, unsigned int);
	if (!nbr && !info->prec)
		return (width_edge_case(fd, info));
	if (info->spec == 'x')
		str = ft_litoa_base(nbr, HEXBASELOW);
	else
		str = ft_litoa_base(nbr, HEXBASEUP);
	if (!str)
		return (FAIL);
	if (!get_precision_base(info, &str))
		return (FAIL);
	if (!prefix_and_width(nbr, &str, info))
		return (FAIL);
	counter += ft_putstr_fd(str, fd);
	free (str);
	return (counter);
}

static int	prefix_and_width(unsigned int nbr, char **str, t_printf_info *info)
{
	if (info->alt && !info->left && info->pad == '0' && info->width != EMPTY)
	{
		info->width -= 2;
		if (!get_width(info, str))
			return (FAIL);
		if (!add_prefix(nbr, str, info))
			return (FAIL);
	}
	else
	{
		if (!add_prefix(nbr, str, info))
			return (FAIL);
		if (!get_width(info, str))
			return (FAIL);
	}
	return (1);
}

static int	add_prefix(unsigned int nbr, char **str, t_printf_info *info)
{
	if (info->alt && nbr)
	{
		if (info->spec == 'x')
			*str = ft_strjoin_free("0x", str);
		else
			*str = ft_strjoin_free("0X", str);
		if (!str)
			return (0);
	}
	return (1);
}
