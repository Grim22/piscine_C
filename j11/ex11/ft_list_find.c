#include "ft_list.h"

t_list *ft_list_find(t_list *begin_list, void *data_ref,int (*cmp)())
{
	t_list *element;

	element = begin_list;
	while (element)
	{
		if (cmp(element->data, data_ref) == 0)
			return (element);
		element = element->next;
	}
	return (0);
}
