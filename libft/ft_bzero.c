/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:34:48 by marigome          #+#    #+#             */
/*   Updated: 2024/04/19 14:27:40 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
}

/*#include <stdio.h>
int main(void)
{
	char prueba[] = "Hola que tal";
	ft_bzero(prueba, 3);
	printf("%s", prueba);
	return (0);
}*/