#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list **begin_list)
{
	t_list *element;
	element = *begin_list;
	while((*begin_list))
	{
		element = *begin_list;
		*begin_list = (*begin_list)->next;
		free(element);
	}
}
