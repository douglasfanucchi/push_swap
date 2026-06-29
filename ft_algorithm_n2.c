#include "push_swap.h"

t_state	ft_bubble_sort(t_stack *a, t_stack *b)
{
	t_state	state;
    t_bool  sorted;

    while (1)
    {
        sorted = TRUE;
        while (a->size)
        {
            if (a->size > 1 && a->arr[0] > a->arr[1])
            {
                sorted = FALSE;
                ft_exec_operation(&state, a, b, ft_swap_a);
            }
            ft_exec_operation(&state, a, b, ft_push_b);
        }
        while (b->size)
        {
            if (b->size > 1 && b->arr[0] < b->arr[1])
                ft_exec_operation(&state, a, b, ft_swap_b);
            ft_exec_operation(&state, a, b, ft_push_a);
        }
        if (sorted)
            break ;
    }

	return (state);
}
