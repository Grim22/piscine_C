#include "ft_list.h"
#include <stdio.h>

void ft_list_sort(t_list **begin_list, int (*cmp)());

int		ft_strcmp(int *a, int *b)
{
	return (*a - *b);
}

int main()
{
	int a = 110;
	int b = 44;
	int c = 1222;
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
	ft_list_sort(&begin_list, &ft_strcmp);
	while(begin_list)
	{
		p = begin_list->data;
		printf("%d\n", *p);	
		begin_list = begin_list->next;

	}
}
