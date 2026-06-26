/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dode-lim <dode-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:46:46 by dode-lim          #+#    #+#             */
/*   Updated: 2026/06/25 18:56:06 by dode-lim         ###   ########.fr       */
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

typedef enum e_strategy {
	adaptative,
	simple,
	medium,
	complex
} t_strategy;

typedef struct s_program {
	t_bool		bench;
	t_state		state;
	double		disorder;
	t_strategy	strategy;
} t_program;

typedef struct s_arr {
	int 	len;
	void	*elements;
} t_arr;

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
t_bool	ft_exec_operation(t_state *state, t_stack *stack_a, t_stack *stack_b,
			t_operations (*f)(t_stack *stack_a, t_stack *stack_b));
char	*ft_get_operation_label(t_operations op);
void	ft_state_init(t_state *state);
int		ft_state_print(const t_state *state);
int		ft_state_get_operation_count(const t_state *state, t_operations op);
t_bool	ft_state_update(t_state *state, t_operations op);
void	ft_state_clear(t_state *state);
t_bool	ft_is_valid_flag(const char *str);
t_bool	ft_is_valid_numeric_set(const char *str);
t_arr	ft_convert_numbers_input_to_int_array(const char **input);
t_bool	ft_less_than_int(void *elements, int i, int j);
void	ft_swap_int(void *elements, int i, int j);
t_bool	ft_less_than_pair(void *elements, int i, int j);
void	ft_swap_pair(void *elements, int i, int j);
void	ft_quicksort(t_arr arr, size_t bytes, t_bool (*lt)(void *, int ,int), void (*swap)(void *, int, int));
t_bool		ft_has_duplicated_numbers(const char **number_sets);
t_bool		ft_is_flag(const char *str);
void		ft_program_flag_update(const char *input, t_program *program);
t_arr		ft_normalize_int_arr(t_arr *arr);
t_stack		ft_int_arr_to_normalized_stack(t_arr *arr);
void		ft_parse_flags(t_program *program, const char **input);
t_stack		ft_parse_numbers(const char **input);
t_bool		ft_input_validator(const char **input);
t_operations	ft_swap_a(t_stack *a, t_stack *b);
t_operations	ft_swap_b(t_stack *a, t_stack *b);
t_operations	ft_swap_ss(t_stack *a, t_stack *b);
t_operations	ft_push_a(t_stack *a, t_stack *b);

#endif
