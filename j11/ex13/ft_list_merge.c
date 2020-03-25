#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *element;

	if (*begin_list1 == 0)
		*begin_list1 = begin_list2;
	else
	{
		element = *begin_list1;
		while (element->next)
			element = element->next;
		element->next = begin_list2;
	}
}
