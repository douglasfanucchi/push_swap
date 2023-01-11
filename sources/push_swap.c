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
}

t_item	**create_stack(int size, char **numbers)
{
	t_item	**stack;
	t_item	*item;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_item **) * size);
	if (!stack)
		return (NULL);
	while (i < size)
	{
		item = malloc(sizeof(t_item));
		item->value = ft_atoi(numbers[i]);
		stack[i] = item;
		i++;
	}
	set_items_indexes(stack, size);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_item	**stack;
	int		stack_size;

	if (argc < 2)
		return (0);
	validate_argv(argv);
	stack_size = argc - 1;
	stack = create_stack(stack_size, argv + 1);
	if (!stack)
		return (1);
	return (0);
}
