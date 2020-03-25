#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_list;

	new_list = ft_create_elem(data);
	t_list *search;
	search = *begin_list;
	while(search->next)
		search = search->next;
	search->next = new_list;
}

