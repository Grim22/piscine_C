#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *new;
	t_list *run;
	t_list *tmp;

	new = ft_create_elem(data);
	run = *begin_list;
	if (*begin_list && cmp(new->data, run->data) < 0)
	{
		printf("Yes\n");
		*begin_list = new;
		new->next = tmp;
	}
	else
	{
		run = *begin_list;
		while(run && cmp(new->data, run->data) > 0)
		{
			tmp = run;
			run = run->next;
		}
		tmp->next = new;
		new->next = run;
	}
}
