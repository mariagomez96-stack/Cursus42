/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:58:14 by marigome          #+#    #+#             */
/*   Updated: 2024/05/02 13:20:56 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int c)
{
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (c < 0)
	{
		c = -c;
		ft_found_c('-');
		ft_putnbr(c);
	}
	else if (c == 0)
	{
		write(1, "0", 1);
	}
	else if (c > 0 && c <= 9)
	{
		ft_found_c(c + '0');
	}
	else
	{
		ft_putnbr((c / 10));
		ft_found_c((c % 10) + '0');
	}
	return (1);
}

int	ft_found_d(int nb)
{
	int	counter;
	int	n;

	n = nb;
	counter = 1;
	if (n < 0 && n != -2147483648)
	{
		counter++;
		n = -n;
	}
	else
	{
		while (n > 9)
		{
			n /= 10;
			counter++;
		}
	}
	ft_putnbr(nb);
	if (n == -2147483648)
		return (11);
	return (counter);
}
