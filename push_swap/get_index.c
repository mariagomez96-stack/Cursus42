/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:43:54 by marigome          #+#    #+#             */
/*   Updated: 2024/08/08 11:22:28 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Get min index:

Si index = -1 porque no tiene índice asignado,
empezamos a tener en cuenta que la flag sea 0 
(Porque no se ha asignado ese índice como mínimo)
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

void	ft_get_index(t_stack **a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*biggest;
	int		value;

	while (stack_size > 0)
	{
		tmp = *a;
		biggest = NULL;
		value = -2147483648;
		while (tmp)
		{
			if (tmp->data == value && tmp->index == -1)
				tmp->index = 1;
			else if (tmp->data > value && tmp->index == -1)
			{
				value = tmp->data;
				biggest = tmp;
			}
			tmp = tmp->next;
		}
		if (biggest != NULL)
			biggest->index = stack_size;
		stack_size--;
	}
}
