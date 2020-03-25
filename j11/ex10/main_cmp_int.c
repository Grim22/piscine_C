#include "ft_list.h"
#include <stdio.h>

int		ft_strcmp(int *a, int *b)
{
	return (*a - *b);
}

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

void fois_deux(int *a)
{
	*a = 2 * *a;
}

int main()
{
	int a = 8;
	int b = 4;
	int c = 12;
	int d = 21;
	int z = 8;
	t_list *begin_list;
	int *p;
	int *q;
	
	q = &z;
	begin_list = ft_create_elem(&a);
	ft_list_push_front(&begin_list, &b);
	ft_list_push_front(&begin_list, &c);
	ft_list_push_front(&begin_list, &d);
	ft_list_foreach_if(begin_list, &fois_deux, q, &ft_strcmp);
	while(begin_list)
	{
		p = begin_list->data;
		printf("%d\n", *p);	
		begin_list = begin_list->next;

	}
}
