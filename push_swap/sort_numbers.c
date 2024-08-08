/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:37:12 by marigome          #+#    #+#             */
/*   Updated: 2024/08/08 13:14:07 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first(t_stack **a, t_stack **b)
{
	int		size;
	int		push;
	t_stack	*tmp;

	size = stack_size(a);
	push = 0;
	while (push < size / 2)
	{
		tmp = *a;
		if ((tmp->index < size / 2) && (push < size / 2)
			&& ((size - push) <= 3))
		{
			push_b(a, b);
			push++;
		}
		else
		{
			if (tmp->index > tmp->next->index)
				sa(a);
			else
				ra(a);
		}
		tmp = tmp->next;
	}
}
