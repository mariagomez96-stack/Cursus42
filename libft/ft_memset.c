/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:39:12 by marigome          #+#    #+#             */
/*   Updated: 2024/04/19 14:20:01 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*buffer;

	buffer = (char *)b;
	i = 0;
	while (i < len)
	{
		buffer[i] = (char)c;
		i++;
	}
	return (b);
}

/*
int main(void)
{
	char ptr[] = "holaquepasa";
	
	printf("%s", ft_memset(ptr, 'A', 9));
	return (0);
}*/