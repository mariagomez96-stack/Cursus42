/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:13:00 by marigome          #+#    #+#             */
/*   Updated: 2024/05/02 13:01:45 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenhex(unsigned long long n)
{
	unsigned long long	counter;

	counter = 0;
	while (n > 0)
	{
		n /= 16;
		counter++;
	}
	return (counter);
}

int	ft_found_p(uintptr_t ptr)
{
	int	len;

	len = ft_lenhex(ptr);
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	ft_found_x(ptr);
	return (len + 2);
}
