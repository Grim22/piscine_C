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

