/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:48:58 by marigome          #+#    #+#             */
/*   Updated: 2024/08/22 15:04:43 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = *src;
	(*src) = tmp;
}

void	push_a(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
