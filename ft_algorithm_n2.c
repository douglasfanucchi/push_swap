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
            if (a->size > 1 && a->head->n > a->head->next->n)
            {
                sorted = FALSE;
                ft_exec_operation(&state, a, b, ft_swap_a);
            }
            ft_exec_operation(&state, a, b, ft_push_b);
        }
        while (b->size)
        {
            if (b->size > 1 && b->head->n < b->head->next->n)
                ft_exec_operation(&state, a, b, ft_swap_b);
            ft_exec_operation(&state, a, b, ft_push_a);
        }
        if (sorted)
            break ;
    }

	return (state);
}
