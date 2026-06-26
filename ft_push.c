#include "push_swap.h"

t_operations	ft_push_a(t_stack *a, t_stack *b)
{
	int	n;
	if (!b->size)
		return (pa);
	n = ft_stack_peek(b);
	ft_stack_pop(b);
	ft_stack_push(a, n);
	return (pa);
}

t_operations	ft_push_b(t_stack *a, t_stack *b)
{
	int	n;
	if (!a->size)
		return (pb);
	n = ft_stack_peek(a);
	ft_stack_pop(a);
	ft_stack_push(b, n);
	return (pb);
}
