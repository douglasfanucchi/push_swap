/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:17:21 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/18 19:29:45 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_operation_label(t_operations op)
{
	if (op == sa)
		return (ft_strdup("sa"));
	else if (op == sb)
		return (ft_strdup("sb"));
	else if (op == ss)
		return (ft_strdup("ss"));
	else if (op == pa)
		return (ft_strdup("pa"));
	else if (op == pb)
		return (ft_strdup("pb"));
	else if (op == ra)
		return (ft_strdup("ra"));
	else if (op == rb)
		return (ft_strdup("rb"));
	else if (op == rr)
		return (ft_strdup("rr"));
	else if (op == rra)
		return (ft_strdup("rra"));
	else if (op == rrb)
		return (ft_strdup("rrb"));
	else if (op == rrr)
		return (ft_strdup("rrr"));
	return (NULL);
}

static void	free_matrix(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static t_list	*ft_convert_numbers_input_to_tlist(const char **input)
{
	int		j;
	char	**set;
	t_list	*list;
	int		*number;

	list = NULL;
	while (*input)
	{
		j = 0;
		set = ft_split(*(input++), ' ');
		while (set[j])
		{
			number = (int *)malloc(sizeof(int));
			if (!number)
			{
				ft_lstclear(&list, free);
				free_matrix(set);
				return (NULL);
			}
			*number = ft_atoi(set[j++]);
			ft_lstadd_back(&list, ft_lstnew(number));
		}
		free_matrix(set);
	}
	return (list);
}

t_int_arr	ft_convert_numbers_input_to_int_array(const char **input)
{
	int			i;
	t_int_arr	arr;
	t_list		*list;
	t_list		*node;

	arr.len = 0;
	list = ft_convert_numbers_input_to_tlist(input);
	if (!list)
		return (arr);
	arr.numbers = malloc(sizeof(int) * (ft_lstsize(list)));
	if (!arr.numbers)
	{
		ft_lstclear(&list, free);
		return (arr);
	}
	node = list;
	i = 0;
	while (node)
	{
		arr.numbers[i++] = *((int *)node->content);
		node = node->next;
	}
	arr.len = i;
	ft_lstclear(&list, free);
	return (arr);
}

void	ft_quicksort(t_int_arr arr)
{
	t_int_arr	arr_left;
	t_int_arr	arr_right;
	int			pivot;
	int			l;
	int			r;

	if (arr.len < 2)
		return ;
	pivot = arr.len - 1;
	l = 0;
	r = 0;
	while (r < arr.len)
	{
		if (arr.numbers[r] < arr.numbers[pivot])
			ft_swap(arr.numbers + r, arr.numbers + l++);
		r++;
	}
	ft_swap(arr.numbers + pivot, arr.numbers + l);
	arr_left.len = l;
	arr_left.numbers = arr.numbers;
	arr_right.len = arr.len - l - 1;
	arr_right.numbers = arr.numbers + l + 1;
	ft_quicksort(arr_left);
	ft_quicksort(arr_right);
}
