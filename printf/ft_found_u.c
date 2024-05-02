/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:10:38 by marigome          #+#    #+#             */
/*   Updated: 2024/05/02 12:34:31 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen_unsigned(unsigned int n)
{
	int				len;
	unsigned int	nb;

	nb = n;
	len = 1;
	if (nb == 4294967295)
		len = 10;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_found_u(unsigned int n)
{
	unsigned int	nb;
	int				len;
	char			c;

	nb = n;
	len = ft_numlen_unsigned(nb);
	if (n == 4294967295)
		write(1, "4294967295", 10);
	while (n >= 10)
	{
		ft_found_u(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	return (len);
}
