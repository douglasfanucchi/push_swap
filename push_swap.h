/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:46:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/16 19:03:46 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_dlist {
	int				n;
	struct s_dlist	*prev;
	struct s_dlist	*next;
} t_dlist;

t_dlist	*ft_dlstnew(int n);
void	ft_dlstadd_front(t_dlist **head, t_dlist *new);
void	ft_dlstadd_back(t_dlist **head, t_dlist *new);
void	ft_dlstclear(t_dlist **head);
t_dlist	*ft_dlst_pop(t_dlist **head);

#endif
