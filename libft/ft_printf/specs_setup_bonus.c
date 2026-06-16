/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_setup_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:34:55 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 10:04:58 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	width_setup(const char **format, t_printf_info *info);
static void	precision_setup(const char **format, t_printf_info *info);
static void	flags_setup(const char **format, t_printf_info *info);

void	init_specification_info(t_printf_info *info)
{
	info->alt = FALSE;
	info->space = FALSE;
	info->left = FALSE;
	info->showsign = FALSE;
	info->pad = ' ';
	info->width = EMPTY;
	info->prec = EMPTY;
	info->spec = '\0';
}

int	setup_specification_info(const char **format, int *counter, \
		t_printf_info *info)
{
	flags_setup(format, info);
	if (info->left)
		info->pad = ' ';
	if (ft_isdigit(**format))
		width_setup(format, info);
	if (**format == '.')
		precision_setup(format, info);
	if (info->width > INT_MAX || info->prec > INT_MAX)
		return (FAIL);
	info->spec = **format;
	if (!ft_strchr("cspdifuxX%", info->spec))
		return (FAIL);
	if (info->spec == 'c' || info->spec == 's')
		info->pad = ' ';
	if (info->spec == '%')
	{
		info->width = EMPTY;
		info->prec = EMPTY;
	}
	return (*counter);
}

static void	flags_setup(const char **format, t_printf_info *info)
{
	while (ft_strchr("# -+0", **format))
	{
		if (**format == '#')
			info->alt = TRUE;
		if (**format == ' ')
			info->space = TRUE;
		if (**format == '-')
			info->left = TRUE;
		if (**format == '+')
			info->showsign = TRUE;
		if (**format == '0')
			info->pad = '0';
		(*format)++;
	}
}

static void	width_setup(const char **format, t_printf_info *info)
{
	info->width = 0;
	while (ft_isdigit(**format))
	{
		info->width = info->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void	precision_setup(const char **format, t_printf_info *info)
{
	(*format)++;
	info->prec = 0;
	while (**format == '0')
		(*format)++;
	while (ft_isdigit(**format))
	{
		info->prec = info->prec * 10 + (**format - '0');
		(*format)++;
	}
}
