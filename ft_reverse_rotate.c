#include "push_swap.h"

t_operations	ft_reverse_rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size < 2)
		return (rra);
	ft_stack_reverse_rotate(a);
	return (rra);
}
