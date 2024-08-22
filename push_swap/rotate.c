/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:52:10 by marigome          #+#    #+#             */
/*   Updated: 2024/08/22 15:07:26 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*a || (*a)->next == NULL)
		return ;
	tmp = *a;
	tail = stack_tail(*a);
	*a = tmp->next;
	tail->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}

