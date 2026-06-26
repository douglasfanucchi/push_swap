#include "push_swap.h"

t_operations	ft_reverse_rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size < 2)
		return (rra);
	ft_stack_reverse_rotate(a);
	return (rra);
}

t_operations	ft_reverse_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->size < 2)
		return (rrb);
	ft_stack_reverse_rotate(b);
	return (rrb);
}

t_operations	ft_reverse_rotate_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate_a(a, NULL);
	ft_reverse_rotate_b(NULL, b);
	return (rrr);
}
