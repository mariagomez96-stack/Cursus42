/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:54:33 by marigome          #+#    #+#             */
/*   Updated: 2024/08/27 09:48:48 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_position;
		if (tmp_b->target_position > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_position) * -1;
		tmp_b = tmp_b->next;
	}
}

void	cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest_move;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest_move = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < cheapest_move)
		{
			cheapest_move = abs(tmp->cost_a) + abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
