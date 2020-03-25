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


void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *parcours;
	t_list *tmp;

	parcours = *begin_list;
	tmp = 0;
	while (parcours->next)
	{
		if (cmp(parcours->data, parcours->next->data) > 0)
		{
			tmp = parcours->data;
			parcours->data = parcours->next->data;
			parcours->next->data = tmp;
			parcours = *begin_list;
		}
		else
			parcours = parcours->next;
	}
}

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
	
