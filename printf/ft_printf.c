/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:06 by marigome          #+#    #+#             */
/*   Updated: 2024/04/26 13:28:18 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static void	ft_format(va_list args, char *str, size_t *counter)
{
	if (*str == 'c')
	{
		ft_putchar_fd(*str, &counter);
	}
	else if (*str == 's')
	{
		ft_putstr_fd(str, counter);
	}
	else if 
}


int	ft_printf(char const *str, ...)
{
	size_t	counter;
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
		}
	}
	
}
*/

#include <stdio.h>
int main(void)
{
	int v = 234;
	printf("%i", v);
}