/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:24 by dfanucch          #+#    #+#             */
/*   Updated: 2023/01/10 17:44:25 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include <libft.h>

void	ft_rotate(int *stack, int size);
void	ft_reverse_rotate(int *stack, int size);
void	ft_push(int *origin, int *dest, int *origin_size, int *dest_size);
void	ft_swap(int *stack, int size);
void	ft_swap_both(int *stack_a, int *stack_b, int size_a, int size_b);

#endif
