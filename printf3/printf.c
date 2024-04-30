/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:24:21 by marigome          #+#    #+#             */
/*   Updated: 2024/04/30 14:04:04 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_found_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_found_s(char *s, int counter)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		counter++;
	}
	return (counter);
}

int	ft_found_d(int c)
{
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (c < 0)
	{
		c = -c;
		ft_found_d(c);
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
		ft_found_d((c / 10));
		ft_found_c((c % 10) + '0');
	}
	return (1);
}

int	ft_numlen(int nb)
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
	ft_found_d(nb);
	if (n == -2147483648)
		return (11);
	return (counter);
}
int ft_lenhex(int n)
{
	int	counter;

	counter = 0;
	while (n > 0)
	{
		n /= 16;
		counter++;
	}
	return (counter);
}

int	ft_numlen_x(int n)
{
	unsigned int	nb;

	nb = n;
	if (nb == 0)
	{
		ft_found_c('0');
	}
	else if (nb >= 16)
	{
		ft_numlen_x(nb / 16);
		ft_numlen_x(nb % 16);
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

int	ft_numlen_X(int n)
{
	unsigned int	nb;

	nb = n;
	if (nb == 0)
	{
		ft_found_c('0');
	}
	else if (nb >= 16)
	{
		ft_numlen_X(nb / 16);
		ft_numlen_X(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_found_c(nb + '0');
		else
			ft_found_c((nb + 'W') - 32);
	}
	return (ft_lenhex(n));
}

int	ft_found_character(va_list args, const char *s, int counter, int i)
{
	if (s[i] == 'c')
	{
		counter += ft_found_c(va_arg(args, int));
	}
	else if (s[i] == 's')
	{
		counter = ft_found_s(va_arg(args, char *), counter);
	}
	else if ((s[i] == 'd') || (s[i] == 'i'))
	{
		counter += ft_numlen(va_arg(args, int));
	}
	else if (s[i] == 'x')
	{
		counter += ft_numlen_x(va_arg(args, int));
	}
	else if (s[i] == 'X')
	{
		counter += ft_numlen_X(va_arg(args, int));
	}
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			counter = ft_found_character(args, s, counter, i);
			i++;
		}
		else
		{
			counter += ft_found_c((char)s[i]);
			i++;
		}
	}
	va_end(args);
	return (counter);
}

int main (void)
{
	int	var1;
	int	var2;

	var1 = ft_printf("Me ----> s:  %s, d: %d, i: %i, x: %x, X: %X\n", "toto", 423, 423, 423, 423);
	var2 = printf("Me ----> s:  %s, d: %d, i: %i, x: %x, X: %X\n", "toto", 423, 423, 423, 423);
	printf("Me -> %d\n", var1);
	printf("Oficial -> %d\n", var2);
	return (0);
}
