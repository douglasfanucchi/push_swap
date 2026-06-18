/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:46:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/18 15:51:11 by dode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_dlist {
	int				n;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_stack {
	int		size;
	t_dlist	*head;
}	t_stack;

typedef enum e_operations {
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_operations;

typedef struct s_state {
	int	count_ops[11];
	int	total_ops;
}	t_state;

t_dlist	*ft_dlstnew(int n);
void	ft_dlstadd_front(t_dlist **head, t_dlist *_new);
void	ft_dlstadd_back(t_dlist **head, t_dlist *_new);
void	ft_dlstclear(t_dlist **head);
t_dlist	*ft_dlst_pop(t_dlist **head);
void	ft_stack_init(t_stack *stack);
int		ft_stack_push(t_stack *stack, int n);
int		ft_stack_pop(t_stack *stack);
int		ft_stack_peek(const t_stack *stack);
void	ft_stack_clear(t_stack *stack);

#endif
