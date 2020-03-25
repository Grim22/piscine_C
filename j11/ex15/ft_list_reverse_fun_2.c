#include "ft_list.h"
#include <stdio.h>

void ft_list_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list *prev;
	t_list *next;

	tmp = *begin_list;
	prev = 0;
	while (tmp)
	{
		next = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = next;
	}
	*begin_list = prev;

}

void ft_list_reverse_fun(t_list *begin_list)
{
	t_list *element;
	t_list *tmp;

	if (begin_list != 0)
	{
		element = begin_list->next;
		ft_list_reverse(&element);
		printf("Hello\n");
		begin_list->next = element;
		element = begin_list;
		while (element->next)
		{
			tmp = element->data;
			element->data = element->next->data;
			element->next->data = tmp;
			element = element->next;
		}
	}
}


