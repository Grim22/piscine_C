#include "ft_list.h"
#include <stdio.h>

/*int ft_list_size(t_list *begin_list)
  {
  int i;

  i = 0;
  while(begin_list)
  {
  begin_list = begin_list->next;
  i++;
  }
  return(i);
  }*/

void ft_list_reverse(t_list **begin_list)
{
	int size;
	int i;
	void *data;
	t_list *elem;

	if (begin_list != 0)
	{
		size = ft_list_size(*begin_list);
		elem = ft_create_elem(ft_list_at(*begin_list, 1)->data);
		i = 2;
		while (i <= size)
		{	
			ft_list_push_front(&elem, ft_list_at(*begin_list, i)->data);
			i++;
		}
		*begin_list = elem;
	} 
}

