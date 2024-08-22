/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:30:45 by marigome          #+#    #+#             */
/*   Updated: 2024/08/22 14:03:09 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_moves(t_stack **tmp, int first, int second, int third)
{
	if ((first < second) && (first < third) && (second > third))
	{
		rra(tmp);
		sa(tmp);
	}
	else if ((first > second) && (first < third) && (second < third))
		sa(tmp);
	else if ((first < second) && (first > third) && (second > third))
		rra(tmp);
	else if ((first > second) && (first > third) && (second < third))
		ra(tmp);
	else if ((first > second) && (first > third) && (second > third))
	{
		ra(tmp);
		sa(tmp);
	}
}

void	ft_sort_three(t_stack **a)
{
	int		first;
	int		second;
	int		third;
	t_stack	*tmp;

	tmp = *a;
	first = tmp->data;
	second = tmp->next->data;
	third = tmp->next->next->data;
	if (checker_sort(tmp))
		return ;
	else
		ft_moves(a, first, second, third);
}



