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

void	ft_dlstadd_back(t_dlist **head, t_dlist *new)
{
	if (!*head)
		return (ft_dlstadd_front(head, new));
	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev->next = new;
	(*head)->prev = new;
}

void	ft_dlstclear(t_dlist **head)
{
	t_dlist	*tmp;

	if (!*head)
		return ;
	(*head)->prev->next = NULL;
	while (*head)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}
}

t_dlist	*ft_dlst_pop(t_dlist **head)
{
	t_dlist	*node;

	node = *head;
	if (!node)
		return (NULL);
	if ((*head)->next == (*head))
	{
		*head = NULL;
		node->prev = NULL;
		node->next = NULL;
		return (node);
	}
	(*head)->prev->next = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	(*head) = (*head)->next;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
