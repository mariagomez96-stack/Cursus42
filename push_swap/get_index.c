#include "push_swap.h"

/*Get min index:

Si index = -1 porque no tiene índice asignado, empezamos a tener en cuenta que la flag sea 0 (Porque no se ha asignado ese índice como mínimo)
y que el índice que se esté comparando sea menor que el asignado

Get index:
Le asignamos índices al stack a partiendo del mínimo*/


t_stack	*get_min_index(t_stack **a)
{
    t_stack	*tmp;
	t_stack	*min;
	int		flag_min;

	tmp = *a;
	min = NULL;
	flag_min = 0;
	if (tmp)
	{
		while (tmp)
		{
			if ((tmp->index == -1) && (!flag_min || tmp->data < min->data))
			{
				min = tmp;
				flag_min = 1;
			}
			tmp = tmp->next;
		}
	}
	return (min);
}

void	get_index(t_stack **a)
{
	t_stack	*tmp;
	int		index;

	tmp = get_min_index(a);
	index = 0;
	while (tmp)
	{
		tmp->index = index++;
		tmp = get_min_index(a);
	}
}