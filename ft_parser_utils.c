/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:55:16 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/25 16:55:30 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_is_flag(const char *str)
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
	t_arr	arr;
	int		i;
	int		*numbers;

	arr = ft_convert_numbers_input_to_int_array(number_sets);
	numbers = (int *)arr.elements;
	if (arr.len == 0)
		return (TRUE);
	ft_quicksort(arr, sizeof(int), ft_less_than_int, ft_swap_int);
	i = 0;
	while (i < arr.len - 1)
	{
		if (numbers[i] == numbers[i + 1])
		{
			free(numbers);
			return (TRUE);
		}
		i++;
	}
	free(arr.elements);
	return (FALSE);
}

void	ft_program_flag_update(const char *input, t_program *program)
{
	if (ft_strcmp(input, "--adaptative") == 0)
		program->strategy = adaptative;
	else if (ft_strcmp(input, "--simple") == 0)
		program->strategy = simple;
	else if(ft_strcmp(input, "--medium") == 0)
		program->strategy = medium;
	else if(ft_strcmp(input, "--complex") == 0)
		program->strategy = complex;
	else if(ft_strcmp(input, "--bench") == 0)
		program->bench = TRUE;
}
