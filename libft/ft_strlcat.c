/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:18:36 by marigome          #+#    #+#             */
/*   Updated: 2024/04/10 19:42:15 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Me permite concatenar de forma segura src a dest. 
Para ello utilizo esta función, para especificar que tamaño de buffer
 voy a necesitar yo en la concatenación (dstsize)
 Calculo el tamaño de destino y el tamaño de origen.
  Si el tamaño que yo especifico es menor o igual que el tamaño de 
 destino, al tamaño de origen le sumo el tamaño que yo especifico.
En caso contrario,
 si el tamaño que yo esepcifico es mayor que el tamaño de destino,
me provocaría buffer, por lo que
 Tengo que sumarle al tamaño de origen, el tamaño de destino.
 Luego siempre lo tengo que marcar con un nulo a destino*/
//#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	sum;

	i = 0;
	j = 0;
	sum = 0;
	while (src[sum])
		sum++;
	while (dst[j] != '\0')
		j++;
	if (dstsize <= j)
		sum += dstsize;
	else
		sum += j;
	while (src[i] && (j + 1) < dstsize)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (sum);
}

/*int main(void)
{
	char dest[50] = "Hola que tal12345678";
	char src[] = "QQQQ";
	printf("%zu", ft_strlcat(dest, src, sizeof(dest)));
	
	return (0);
}*/