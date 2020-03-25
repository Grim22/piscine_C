#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int i;
	t_list *element;

	i = 1;
	if (nbr == 0)
		return (0);
	element = begin_list;
	while (element && i < nbr)
	{
		element = element->next;
		i++;
	}
	return (element);
}
	
