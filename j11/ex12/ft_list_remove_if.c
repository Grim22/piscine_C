#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *element;
	t_list *prev;
	t_list *tmp;

	if (cmp(*begin_list, data_ref) == 0)
	{
		*begin_list = (*begin_list)->next;
	}
	else
	{
		prev = *begin_list;
		element = *begin_list;
		while (element)
		{
			tmp = element;
			if(cmp(element->data, data_ref) == 0)
			{
				prev->next = element->next;
				free(element);
			}
			prev = tmp;
			element = tmp->next;
		}
	}
}
