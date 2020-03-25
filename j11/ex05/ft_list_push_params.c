#include "ft_list.h"


void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}

t_list *ft_list_push_params(int ac, char **av)
{
	t_list *element;
	int i;

	i = 2;
	if (ac == 1)
		return(0);
	element = ft_create_elem(av[1]);
	while(i < ac)
	{
		ft_list_push_front(&element, av[i]);
			i++;
	}
	return (element);
}

