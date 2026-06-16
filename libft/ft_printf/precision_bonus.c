/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:34:53 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/07 11:19:06 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*add_sign_and_space(t_printf_info *info, char *str, int neg);

char	*get_precision_diu(t_printf_info *info, char **str)
{
	char	*tmp;
	int		neg;

	neg = FALSE;
	tmp = *str;
	if (**str == '-')
	{
		*str = ft_strtrim(*str, "-");
		free(tmp);
		if (!*str)
			return (NULL);
		neg = TRUE;
	}
	if (!get_precision_base(info, str))
		return (NULL);
	*str = add_sign_and_space(info, *str, neg);
	if (!*str)
		return (NULL);
	if (neg)
		*str = ft_strjoin_free("-", str);
	return (*str);
}

static char	*add_sign_and_space(t_printf_info *info, char *str, int neg)
{
	if (info->showsign && !neg && info->spec != 'u')
		str = ft_strjoin_free("+", &str);
	else if (info->space && !neg && info->spec != 'u')
		str = ft_strjoin_free(" ", &str);
	return (str);
}

char	*get_precision_s(t_printf_info *info, char **str)
{
	char	*tmp;

	tmp = *str;
	*str = ft_substr(*str, 0, info->prec);
	free(tmp);
	if (!*str)
		return (NULL);
	return (*str);
}

char	*get_precision_base(t_printf_info *info, char **str)
{
	int		len;
	int		i;
	char	*precision;
	char	*tmp;

	len = (int) ft_strlen(*str);
	if (!info->prec || info->prec <= len)
		return (*str);
	precision = malloc(info->prec - len + 1);
	if (!precision)
		return (NULL);
	i = 0;
	while (len + i < info->prec)
	{
		precision[i] = '0';
		i++;
	}
	precision[i] = '\0';
	tmp = *str;
	*str = ft_strjoin(precision, *str);
	free(tmp);
	free(precision);
	return (*str);
}
