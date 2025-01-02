/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:59:07 by marigome          #+#    #+#             */
/*   Updated: 2024/08/22 15:38:08 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int		i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack	*ft_new_node(long int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = n;
	node->index = 0;
	node->position = -1;
	node->target_position = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

void	ft_add_stack(t_stack **stack_a, t_stack *new_node)
{
	t_stack	*run;

	run = *stack_a;
	if (!new_node)
		return ;
	if (!*stack_a)
	{
		*stack_a = new_node;
		return ;
	}
	run = stack_tail(*stack_a);
	run->next = new_node;
}

t_stack	*stack_tail(t_stack *a)
{
	while (a && a->next != NULL)
		a = a->next;
	return (a);
}

t_stack	*stack_before_tail(t_stack *a)
{
	while (a && a->next->next != NULL)
		a = a->next;
	return (a);
}
