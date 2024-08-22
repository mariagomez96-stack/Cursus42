/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:37:12 by marigome          #+#    #+#             */
/*   Updated: 2024/08/22 15:13:15 by marigome         ###   ########.fr       */
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
	while (size > 6  && i < size && push < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			push_b(a, b);
			push++;
			//printf("Pushed to stack_b, push count: %d\n", push);
		}
		else
		{	
			ra(a);
			//printf("Rotated stack_a\n");
		}
		i++;
	}
	while (size - push > 3)
	{
			push_b(a ,b);
			push++;
	}
}

void	sort_stack(t_stack **a)
{
	int	min_position;
	int	moves;

	min_position = position_lowest_index(a);
	moves = stack_size(*a);
	if (min_position > moves / 2)
	{
		while (min_position < moves)
		{	
			rra(a);
			min_position++;
		}
	}
	else
	{
		while (min_position > 0)
		{
			ra(a);
			min_position--;
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


