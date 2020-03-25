#include "ft_list.h"

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
			
