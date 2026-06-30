/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:31:59 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/30 14:23:31 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	ft_compute_disorder(const char **input)
{
	t_arr	arr;
	int		i[2];
	int		mistakes;
	int		total_pairs;

	while (ft_is_flag(*input))
		input++;
	arr = ft_convert_numbers_input_to_int_array(input);
	i[0] = -1;
	mistakes = 0;
	total_pairs = 0;
	while (++i[0] < arr.len - 1)
	{
		i[1] = i[0];
		while (++i[1] < arr.len)
		{
			if (ft_less_than_int(arr.elements, i[1], i[0]))
				mistakes++;
			total_pairs++;
		}
	}
	free(arr.elements);
	if (!total_pairs)
		return (0);
	return ((mistakes * 1.0) / total_pairs);
}

int	main(int argc, const char **argv)
{
	t_program	program;
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		return (0);
	if (!ft_input_validator(argv + 1))
	{
		ft_printf_fd(2, "Error\n");
		return (1);
	}
	program.disorder = ft_compute_disorder(argv + 1);
	ft_parse_flags(&program, argv + 1);
	a = ft_parse_numbers(argv + 1);
	ft_stack_init(&b);
	// t_state	state = ft_bubble_sort(&a, &b);
	// ft_state_print(&state);
	// ft_state_clear(&state);
	ft_stack_clear(&a);
}
