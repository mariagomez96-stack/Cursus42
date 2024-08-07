/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:59:07 by marigome          #+#    #+#             */
/*   Updated: 2024/08/08 13:18:28 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
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
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack	*ft_add_stack(t_stack **stack_a, t_stack *new_node)
{
	t_stack	*run;

	run = *stack_a;
	if (!new_node)
		return (NULL);
	if (!*stack_a)
	{
		*stack_a = new_node;
	}
	else
	{
		while (run->next)
			run = run->next;
		run->next = new_node;
	}
	return (*stack_a);
}

t_stack	*stack_tail(t_stack *a)
{
	if (!a || (a)->next == NULL)
		return (NULL);
	while (a->next != NULL)
		a = (a)->next;
	return (a);
}

t_stack	*stack_before_tail(t_stack *a)
{
	if (!a || a->next == NULL)
		return (NULL);
	while (a->next->next != NULL)
		a = a->next;
	return (a);
}
