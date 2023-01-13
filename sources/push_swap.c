/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:58 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/12 20:33:50 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	validate_argv(char **argv)
{
	char	**params;

	params = argv + 1;
	while (*params)
	{
		if (!ft_is_number(*params))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		params++;
	}
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	stack_size;

	if (argc < 2)
		return (0);
	validate_argv(argv);
	stack_size = argc - 1;
	stack_a = create_stack(stack_size, argv + 1);
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(int) * stack_size);
	if (ft_is_ordered(stack_a, stack_size))
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	if (stack_size < 6)
		ft_small_stack_sort(stack_a, stack_b, stack_size, 0);
	else
		ft_radix(stack_a, stack_b, stack_size, 0);
	free(stack_a);
	free(stack_b);
	return (0);
}
