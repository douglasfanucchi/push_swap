#include "push_swap.h"

t_operations	ft_rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size < 2)
		return (ra);
	ft_stack_rotate(a);
	return (ra);
}

t_operations	ft_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->size < 2)
		return (rb);
	ft_stack_rotate(b);
	return (rb);
}
