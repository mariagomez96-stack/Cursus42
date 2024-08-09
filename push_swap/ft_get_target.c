/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 07:51:12 by marigome          #+#    #+#             */
/*   Updated: 2024/08/09 08:03:15 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_target(t_stack **a, int index_b, int limit_max)
{
	int	target;
	int	index_a;
	t_stack	*tmp;

	target = -1;
	tmp = *a;
	while (tmp)
	{
		index_a = tmp->index;
		if ((index_a > index_b) && (index_a < limit_max))
		{
			limit_max = index_a;
			target = tmp->position;
		}
		tmp = tmp->next;
	}
	if (target != -1)
		return (target);
	tmp = *a;
	while (tmp)
	{
		index_a = tmp->index;
		if (index_a < limit_max)
		{
			limit_max = index_a;
			target = tmp->position; 
		}
		tmp = tmp->next;
	}
	return (target);
}