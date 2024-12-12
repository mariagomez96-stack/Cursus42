/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 07:51:12 by marigome          #+#    #+#             */
/*   Updated: 2024/08/27 09:49:57 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_target(t_stack **a, int index_b, int limit_max, int target)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if ((tmp->index > index_b) && (tmp->index < limit_max))
		{
			limit_max = tmp->index;
			target = tmp->position;
		}
		tmp = tmp->next;
	}
	if (limit_max != INT_MAX)
		return (target);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < limit_max)
		{
			limit_max = tmp->index;
			target = tmp->position;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	ft_get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	target_pos = 0;
	ft_get_position(a);
	ft_get_position(b);
	while (tmp_b)
	{
		target_pos = ft_get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_position = target_pos;
		tmp_b = tmp_b->next;
	}
}
