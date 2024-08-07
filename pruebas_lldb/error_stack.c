/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:42:39 by marigome          #+#    #+#             */
/*   Updated: 2024/08/06 13:35:19 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_exit_error(t_stack **a, t_stack **b)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	ft_putstr("Error\n");
	exit(1);
}
