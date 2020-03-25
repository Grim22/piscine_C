#include "ft_list.h"
#include <stdlib.h>

t_list *ft_create_elem(void *data)
{
	t_list *new_list;
	
	if(!(new_list = malloc(sizeof(*new_list))))
		return(0);
	new_list->data = data;
	new_list->next = NULL;
	return(new_list);
}
