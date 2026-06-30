/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:22:36 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/29 21:23:17 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_input_validator(const char **input)
{
	const char	**numbers;

	while (*input && ft_is_flag(*input))
	{
		if (!ft_is_valid_flag(*input))
			return (FALSE);
		input++;
	}
	if (!*input)
		return (FALSE);
	numbers = input;
	while (*input)
	{
		if (!ft_is_valid_numeric_set(*input))
			return (FALSE);
		input++;
	}
	if (ft_has_duplicated_numbers(numbers))
		return (FALSE);
	return (TRUE);
}
