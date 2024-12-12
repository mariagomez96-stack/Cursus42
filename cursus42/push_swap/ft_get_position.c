/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:07:30 by marigome          #+#    #+#             */
/*   Updated: 2024/08/27 09:49:50 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_position(t_stack **a)
{
	int		position;
	t_stack	*tmp;

	position = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->position = position;
		tmp = tmp->next;
		position++;
	}
}

int	position_lowest_index(t_stack **a)
{
	int		min_index;
	int		min_position;
	t_stack	*tmp;

	min_index = INT_MAX;
	tmp = *a;
	ft_get_position(a);
	min_position = tmp->position;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (min_position);
}
