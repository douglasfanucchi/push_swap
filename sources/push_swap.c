/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:58 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 21:38:48 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	validate_argv(char **argv)
{
	char	**params;

	params = argv + 1;
	while (*params)
	{
		if (!ft_is_number(*params))
		{
			ft_putstr_fd("Error.\n", 2);
			exit(1);
		}
		params++;
	}
}

void	free_stack(t_item **stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(stack[i++]);
	free(stack);
}

void	set_items_indexes(t_item **stack, int size)
{
	t_item	**ordered;
	int		i;

	i = 0;
	ordered = malloc(sizeof(t_item **) * size);
	ft_memcpy(ordered, stack, size * sizeof(t_item **));
	ft_quick_sort(ordered, 0, size);
	while (i < size)
	{
		ordered[i]->index = i;
		if (i != size - 1 && ordered[i]->value == ordered[i + 1]->value)
		{
			free_stack(stack, size);
			free(ordered);
			ft_putstr_fd("Error.\n", 2);
			exit(1);
		}
		i++;
	}
	free(ordered);
}

int	*create_stack(int size, char **numbers)
{
	t_item	**stack;
	t_item	*item;
	int		*indexes_stack;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_item **) * size);
	while (i < size)
	{
		item = malloc(sizeof(t_item));
		item->value = ft_atoi(numbers[i]);
		stack[i] = item;
		i++;
	}
	set_items_indexes(stack, size);
	indexes_stack = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		indexes_stack[i] = stack[i]->index;
		i++;
	}
	return (indexes_stack);
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
	stack_b = malloc(sizeof(int) * stack_size);
	if (!stack_a)
		return (1);
	ft_radix(stack_a, stack_b, stack_size, 0);
	return (0);
}
