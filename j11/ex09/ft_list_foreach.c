#include "ft_list.h"

void fois_deux(int *a)
{
	*a = 2 * *a;
}

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *element;

	element = begin_list;
	while(element)
	{
		f(element->data);
		element = element->next;
	}
} 
