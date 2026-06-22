/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char_and_str_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:33:57 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/08 10:24:49 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_in_order(int fd, t_printf_info *info, char c, char *pad);
static char	*get_prec_and_width_s(t_printf_info *info, char **str);

int	convert_c_and_percent(int fd, t_printf_info *info, va_list args)
{
	char	*pad;
	char	c;
	int		counter;

	pad = ft_calloc (1, sizeof(char));
	if (!pad)
		return (FAIL);
	if (info->width >= 0)
	{
		if (!get_width(info, &pad))
			return (FAIL);
		pad[info->width - 1] = '\0';
	}
	if (info->spec == '%')
		c = '%';
	if (info->spec == 'c')
		c = (unsigned char) va_arg(args, int);
	counter = print_in_order(fd, info, c, pad);
	free (pad);
	return (counter);
}

static int	print_in_order(int fd, t_printf_info *info, char c, char *pad)
{
	int	counter;

	counter = 0;
	if (info->left)
	{
		counter += ft_putchar_fd(c, fd);
		counter += ft_putstr_fd(pad, fd);
	}
	else
	{
		counter += ft_putstr_fd(pad, fd);
		counter += ft_putchar_fd(c, fd);
	}
	return (counter);
}

int	convert_s(int fd, t_printf_info *info, va_list args)
{
	int		counter;
	char	*str;

	counter = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		if (info->prec > 0 && info->prec < 6)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(str);
	if (!str)
		return (FAIL);
	if (!get_prec_and_width_s(info, &str))
		return (FAIL);
	counter += ft_putstr_fd(str, fd);
	free(str);
	return (counter);
}

static char	*get_prec_and_width_s(t_printf_info *info, char **str)
{
	if (info->prec >= 0)
		if (!get_precision_s(info, str))
			return (NULL);
	if (info->width >= 0)
		if (!get_width(info, str))
			return (NULL);
	return (*str);
}
