/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:52:10 by marigome          #+#    #+#             */
/*   Updated: 2024/08/06 11:09:04 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*a || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	tail = stack_tail(*a);
	tail->next = tmp;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
