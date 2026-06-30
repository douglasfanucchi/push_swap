/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:06:05 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/30 17:10:17 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	ft_normalize_int_arr(t_arr *arr)
{
	int		i;
	t_arr	result;
	t_arr	pairs;

	result.len = arr->len;
	result.elements = malloc(sizeof(int) * result.len);
	ft_memmove(result.elements, arr->elements, sizeof(int) * (result.len));
	pairs.len = result.len;
	pairs.elements = malloc(sizeof(int *) * (result.len));
	i = -1;
	while (++i < pairs.len)
	{
		((int **)pairs.elements)[i] = malloc(sizeof(int) * 2);
		((int **)pairs.elements)[i][0] = i;
		((int **)pairs.elements)[i][1] = ((int *)result.elements)[i];
	}
	ft_quicksort(pairs, sizeof(int *), ft_less_than_pair, ft_swap_pair);
	i = -1;
	while (++i < pairs.len)
		((int *)result.elements)[((int **)pairs.elements)[i][0]] = i;
	i = 0;
	while (i < pairs.len)
		free(((int **)pairs.elements)[i++]);
	free(pairs.elements);
	return (result);
}

void	ft_parse_flags(t_program *program, const char **input)
{
	program->bench = FALSE;
	program->strategy = adaptative;
	while (*input && ft_is_flag(*input))
	{
		ft_program_flag_update(*input, program);
		input++;
	}
}

t_stack	ft_int_arr_to_normalized_stack(t_arr *arr)
{
	t_arr	normalized;
	int		i;
	t_stack	stack;

	i = 0;
	normalized = ft_normalize_int_arr(arr);
	ft_stack_init(&stack);
	while (i < normalized.len)
	{
		ft_stack_push(&stack, ((int *)normalized.elements)[i]);
		ft_stack_rotate(&stack);
		i++;
	}
	free(normalized.elements);
	return (stack);
}

t_stack	ft_parse_numbers(const char **input)
{
	t_stack	stack;
	t_arr	numbers;

	while (*input && ft_is_flag(*input))
		input++;
	numbers = ft_convert_numbers_input_to_int_array(input);
	stack = ft_int_arr_to_normalized_stack(&numbers);
	free(numbers.elements);
	return (stack);
}
