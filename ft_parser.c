/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:06:05 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/23 19:13:53 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_is_flag(const char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

t_bool	ft_is_valid_flag(const char *str)
{
	char	**options;

	options = (char *[]){
		"--adaptative",
		"--simple",
		"--medium",
		"--complex",
		"--bench",
		NULL
	};
	if (!ft_is_flag(str))
		return (FALSE);
	while (*options)
	{
		if (ft_strcmp(str, *options) == 0)
			return (TRUE);
		options++;
	}
	return (FALSE);
}

t_bool	ft_is_valid_numeric_set(const char *str)
{
	size_t	i;
	long	n;

	i = 0;
	if (!str[i])
		return (FALSE);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] && !ft_is_valid_numeric_set(str + i))
		return (FALSE);
	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_has_duplicated_numbers(const char **number_sets)
{
	t_int_arr	arr;
	int			i;

	arr = ft_convert_numbers_input_to_int_array(number_sets);
	if (arr.len == 0)
		return (TRUE);
	ft_quicksort(arr);
	i = 0;
	while (i < arr.len - 1)
	{
		if (arr.numbers[i] == arr.numbers[i + 1])
		{
			free(arr.numbers);
			return (TRUE);
		}
		i++;
	}
	free(arr.numbers);
	return (FALSE);
}
