/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 08:44:20 by marigome          #+#    #+#             */
/*   Updated: 2024/04/29 13:26:16 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(int c, size_t counter)
{
	if (c == -2147483648)
	{
		counter += ft_putchar('-');
		counter += ft_putchar('2');
		ft_putnbr(c / 10);
	}
	else if (c < 0)
	{
		counter += ft_putchar('-');
		ft_putnbr(-c);
	}
	else if (c > 0 && c <= 9)
		counter += ft_putchar('0' + c);
	else
		ft_putnbr(c / 10);
	return (counter);
}
