#include "push_swap.h"

void mem_free(char *a)
{
	free(a);
    a = NULL;
}

void    free_stack(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		// printf("%d\n", (*head)->content);
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}
