/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:43:01 by marigome          #+#    #+#             */
/*   Updated: 2024/04/25 09:01:25 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*size_t  ft_strlen(const char *s)
{
	size_t  i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = (ft_strlen(s) + 1);
	j = 0;
	ptr = (char *)malloc(i * sizeof(char));
	if (!ptr)
		return (NULL);
	else
		ft_memcpy(ptr, s, i);
	return (ptr);
}

/*#include <stdio.h>
int main (void)
{
	char    ptr[] = "hola que tal";
	printf("%s", ft_strdup(ptr));
	return (0);
}*/