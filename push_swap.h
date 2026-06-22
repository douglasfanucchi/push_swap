/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:46:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/18 19:17:59 by dode-lim         ###   ########.fr       */
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

typedef unsigned char t_bool;

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
	int		count_ops[11];
	int		total_ops;
	t_list	*ops;
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
void	ft_stack_rotate(t_stack *stack);
void	ft_stack_reverse_rotate(t_stack *stack);
void	ft_exec_operation(t_state *state, t_stack *stack_a, t_stack *stack_b,
			t_operations (*f)(t_stack *stack_a, t_stack *stack_b));
char	*ft_get_operation_label(t_operations op);
void	ft_state_init(t_state *state);
int		ft_state_print(const t_state *state);
int		ft_state_get_operation_count(const t_state *state, t_operations op);
t_bool	ft_state_update(t_state *state, t_operations op);
void	ft_state_clear(t_state *state);

#endif
