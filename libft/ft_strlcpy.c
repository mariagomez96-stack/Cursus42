/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:18:48 by marigome          #+#    #+#             */
/*   Updated: 2024/04/25 08:21:32 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*int main(void)
{
	char dest[50] = "Hola que pasa";
	char src[] = "AAAAaAAAAAAAAAAAAAAAAAAAAAA";
	size_t resultado;
	///printf("%zu", ft_strlcpy(dest, src, sizeof(dest)));
	resultado = ft_strlcpy(dest, src, 50);
	printf("%zu\n", resultado);
	printf("%s\n", dest);
	return (0);
}*/