#include "push_swap.h"

static	void ft_swap_operation(t_stack *stack)
{
	int	first;
	int	second;

	if (!stack->size)
		return ;
	first = ft_stack_peek(stack);
	ft_stack_pop(stack);
	if (!stack->size)
	{
		ft_stack_push(stack, first);
		return ;
	}
	second = ft_stack_peek(stack);
	ft_stack_pop(stack);
	ft_stack_push(stack, first);
	ft_stack_push(stack, second);
}

t_operations	ft_swap_a(t_stack *a, t_stack *b)
{
	(void)b;
	ft_swap_operation(a);	
	return (sa);
}

t_operations	ft_swap_b(t_stack *a, t_stack *b)
{
	(void)a;
	ft_swap_operation(b);
	return (sb);
}
