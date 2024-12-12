/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:43:54 by marigome          #+#    #+#             */
/*   Updated: 2024/08/22 15:00:45 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index(t_stack *a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*biggest;
	int		value;

	while (--stack_size > 0)
	{
		tmp = a;
		biggest = NULL;
		value = INT_MIN;
		while (tmp)
		{
			if (tmp->data == value && tmp->index == 0)
				tmp->index = 1;
			if (tmp->data > value && tmp->index == 0)
			{
				value = tmp->data;
				biggest = tmp;
				tmp = tmp->next;
			}
			else
				tmp = tmp->next;
		}
		if (biggest != NULL)
			biggest->index = stack_size;
	}
}
