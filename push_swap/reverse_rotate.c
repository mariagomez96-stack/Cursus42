/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:50:31 by marigome          #+#    #+#             */
/*   Updated: 2024/08/07 11:56:17 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **a)
{
	t_stack	*tail;
	t_stack	*before_tail;
	t_stack	*first;

	if (!*a || (*a)->next == NULL)
		return ;
	first = *a;
	tail = stack_tail(*a);
	before_tail = stack_before_tail(*a);
	before_tail->next = NULL;
	first = tail;
	first->next = before_tail;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr("rrr\n");
}
