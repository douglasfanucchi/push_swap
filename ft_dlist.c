#include "push_swap.h"

t_dlist	*ft_dlstnew(int n)
{
	t_dlist	*result;

	result = malloc(sizeof(t_dlist));
	if (!result)
		return (NULL);
	result->n = n;
	result->prev = NULL;
	result->next = NULL;
	return (result);
}
