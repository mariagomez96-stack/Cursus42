/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:37:12 by marigome          #+#    #+#             */
/*   Updated: 2024/08/27 09:55:45 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **a, t_stack **b)
{
	int		size;
	int		push;
	int		i;

	size = stack_size(*a);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			push_b(a, b);
			push++;
		}
		else
		{
			ra(a);
		}
		i++;
	}
	while (size - push > 3)
	{
		push_b(a, b);
		push++;
	}
}

void	sort_stack(t_stack **a)
{
	int	target_position;
	int	size;

	target_position = position_lowest_index(a);
	size = stack_size(*a);
	if (target_position > size / 2)
	{
		while (target_position < size)
		{
			rra(a);
			target_position++;
		}
	}
	else
	{
		while (target_position > 0)
		{
			ra(a);
			target_position--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	ft_sort_three(a);
	while (*b)
	{
		ft_get_target_position(a, b);
		ft_cost(a, b);
		cheapest_move(a, b);
	}
	if (!checker_sort(*a))
		sort_stack(a);
}
