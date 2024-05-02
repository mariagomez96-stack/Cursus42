/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:04:50 by marigome          #+#    #+#             */
/*   Updated: 2024/05/02 12:39:05 by marigome         ###   ########.fr       */
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

int	ft_found_x(unsigned long long n)
{
	unsigned long long	nb;

	nb = n;
	if (nb == 0)
	{
		ft_found_c('0');
	}
	else if (nb >= 16)
	{
		ft_found_x(nb / 16);
		ft_found_x(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_found_c(nb + '0');
		else
			ft_found_c((nb + '7') + 32);
	}
	return (ft_lenhex(n));
}
