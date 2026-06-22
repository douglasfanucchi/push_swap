#include "push_swap.h"

void	ft_state_init(t_state *state)
{
    ft_bzero(state, sizeof(t_state));
}

int	ft_state_print(const t_state *state)
{
    t_list  *ptr;
    int     size;

    ptr = state->ops;
    size = 0;
    while (ptr)
    {
        size += ft_printf_fd(1, "%s\n", (char *)ptr->content);
        ptr = ptr->next;
    }
    return (size);
}
