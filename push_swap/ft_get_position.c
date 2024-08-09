/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:07:30 by marigome          #+#    #+#             */
/*   Updated: 2024/08/09 08:09:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_get_position(t_stack **a)
{
    int	position;
	t_stack	*tmp;

	position = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->position = position;
		position++;
		tmp = tmp->next;
	}
}