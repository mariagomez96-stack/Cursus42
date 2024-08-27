/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:50:31 by marigome          #+#    #+#             */
/*   Updated: 2024/08/27 09:54:56 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*tail;
	t_stack	*before_tail;
	t_stack	*tmp;

	if (!*a || (*a)->next == NULL)
		return ;
	tail = stack_tail(*a);
	before_tail = stack_before_tail(*a);
	tmp = *a;
	*a = tail;
	(*a)->next = tmp;
	before_tail->next = NULL;
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
