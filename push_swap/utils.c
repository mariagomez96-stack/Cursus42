/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:21 by marigome          #+#    #+#             */
/*   Updated: 2024/08/27 09:56:07 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
}

int	ft_is_duplicated(t_stack **a)
{
	t_stack	*stack_a;
	t_stack	*runner;

	stack_a = *a;
	while (stack_a)
	{
		runner = stack_a->next;
		while (runner)
		{
			if (stack_a->data == runner->data)
				return (1);
			runner = runner->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

long int	ft_atol(char *src)
{
	long int	res;
	int			counter;
	int			i;

	res = 0;
	counter = 1;
	i = 0;
	if (src[i] == '+')
		i++;
	else if (src[i] == '-')
	{
		counter = -counter;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		res = res * 10 + (src[i] - '0');
		i++;
	}
	return (res * counter);
}

int	checker_sort(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next != NULL)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int	abs(int cost)
{
	if (cost < 0)
		return (cost * -1);
	return (cost);
}
