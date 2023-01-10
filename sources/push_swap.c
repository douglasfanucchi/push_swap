/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:58 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 20:55:32 by dfanucch         ###   ########.fr       */
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
			ft_putstr_fd("Error.\n", 2);
			exit(1);
		}
		params++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	validate_argv(argv);
	return (0);
}
