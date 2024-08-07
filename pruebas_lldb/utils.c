/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:21 by marigome          #+#    #+#             */
/*   Updated: 2024/08/06 13:11:21 by marigome         ###   ########.fr       */
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

int	checker_sort(t_stack **a)
{
	t_stack	*tmp;
	int		counter;

	tmp = *a;
	counter = 0;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			counter++;
		tmp = tmp->next;
	}
	if (counter)
		return (1);
	return (0);
}

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
