/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:06 by marigome          #+#    #+#             */
/*   Updated: 2024/04/29 14:03:20 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_format(va_list args, const char *str)
{
	int	counter2;
	int i;
	
	i = 0;
	counter2 = 0;
	
	if (str[i] == 'c')
		counter2 += ft_putchar(va_arg(args, char));
	/*else if (*str == 's')
		counter2 += ft_putstr(va_arg(args, char *));
	else if (*str == 'i')
		counter2 += ft_putnbr(va_arg(args, int));
	else if (*str == 'd')
		counter2 += ft_putnbr(va_arg(args, int));
	else if (*str == 'u')
		counter2 += ft_putint_fd(va_arg(args, int));
	else if (*str == '%')
		counter2 += ft_putchar(va_arg(args, char));*/
	return (counter2);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_format(args, &str[i]);
		}
		else if (str[i] != '%' && str[i])
		{
			counter += ft_putchar(str[i]);
			i++;
		}
		
	}
	va_end(args);
	return (counter);
}


int main(void)
{
	int result1;
	int result2;

	result1 = ft_printf("La longitud del resultado 1 es, %c\n", 'c');
	result2 = printf("La longitud de la funcion oficial es, %c\n", 'c');
}