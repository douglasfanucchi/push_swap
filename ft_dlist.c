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

void	ft_dlstadd_front(t_dlist **head, t_dlist *new)
{
	if (!*head)
	{
		*head = new;
		(*head)->prev = *head;
		(*head)->next = *head;
		return ;
	}
	new->next = *head;
	new->prev = (*head)->prev;
	(*head)->prev = new;
	new->prev->next = new;
	(*head) = new;
}
