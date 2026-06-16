/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:35:01 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 10:01:59 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*left_justify(t_printf_info *info, char **str);
static char	*right_justify(t_printf_info *info, char **str);
static char	*get_padding(char *str, t_printf_info *info);
static char	*add_sign(char **str, t_printf_info *info, int negative);

char	*get_width(t_printf_info *info, char **str)
{
	if (info->width == EMPTY)
		return (*str);
	if (info->left)
		*str = left_justify(info, str);
	else
		*str = right_justify(info, str);
	if (!*str)
		return (NULL);
	return (*str);
}

static char	*left_justify(t_printf_info *info, char **str)
{
	char	*tmp;
	char	*pad;

	pad = get_padding(*str, info);
	if (!pad)
		return (NULL);
	tmp = *str;
	*str = ft_strjoin(*str, pad);
	free(tmp);
	free(pad);
	return (*str);
}

static char	*right_justify(t_printf_info *info, char **str)
{
	int		move_sign;
	char	*pad;
	char	*tmp;
	int		negative;

	move_sign = FALSE;
	if (info->prec == EMPTY && (**str == '-' || info->showsign || info->space) \
			&& info->pad == '0' && (info->spec == 'd' || info->spec == 'i'))
		move_sign = TRUE;
	pad = get_padding(*str, info);
	if (!pad)
		return (NULL);
	tmp = *str;
	negative = FALSE;
	if (**str == '-')
		negative = TRUE;
	*str = ft_strjoin(pad, *str + move_sign);
	free (tmp);
	free(pad);
	if (!*str)
		return (NULL);
	if (move_sign)
		add_sign(str, info, negative);
	return (*str);
}

static char	*add_sign(char **str, t_printf_info *info, int negative)
{
	char	*tmp;

	tmp = *str;
	if (negative)
		*str = ft_strjoin("-", *str);
	else if (info->showsign)
		*str = ft_strjoin("+", *str);
	else
		*str = ft_strjoin(" ", *str);
	free (tmp);
	return (*str);
}

static char	*get_padding(char *str, t_printf_info *info)
{
	char	*pad;
	char	pad_char;
	int		len;
	int		i;

	pad = (char *)malloc(info->width + 1);
	if (!pad)
		return (NULL);
	len = (int) ft_strlen(str);
	i = 0;
	pad_char = '0';
	if (info->pad == ' ' || info->prec != -1)
		pad_char = ' ';
	while (len + i < info->width)
	{
		pad[i] = pad_char;
		i++;
	}
	pad[i] = '\0';
	return (pad);
}
