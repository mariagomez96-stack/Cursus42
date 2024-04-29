/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:00:19 by marigome          #+#    #+#             */
/*   Updated: 2024/04/29 13:24:24 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int c)
{
	int	counter;

	counter = 0;
	if (c < 0)
	{
		c *= -c;
		ft_putint(c);
	}
	if (c > 9)
	{
		ft_putnbr_u(c / 10);
	}
	else
		counter += ft_putchar('0' + c);
	return (counter);
}
