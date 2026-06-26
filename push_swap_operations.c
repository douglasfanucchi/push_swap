#include "push_swap.h"

t_operations	ft_swap_a(t_stack *a, t_stack *b)
{
	int	first;
	int	second;

	(void)b;
	if (!a->size)
		return (sa);
	first = ft_stack_peek(a);
	ft_stack_pop(a);
	if (!a->size)
	{
		ft_stack_push(a, first);
		return (sa);
	}
	second = ft_stack_peek(a);
	ft_stack_pop(a);
	ft_stack_push(a, first);
	ft_stack_push(a, second);
	return (sa);
}

t_operations	ft_swap_b(t_stack *a, t_stack *b)
{
	int	first;
	int	second;

	(void)a;
	if (!b->size)
		return (sb);
	first = ft_stack_peek(b);
	ft_stack_pop(b);
	if (!b->size)
	{
		ft_stack_push(b, first);
		return (sb);
	}
	second = ft_stack_peek(b);
	ft_stack_pop(b);
	ft_stack_push(b, first);
	ft_stack_push(b, second);
	return (sb);
}
