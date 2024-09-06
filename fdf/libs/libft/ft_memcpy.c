/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:36:34 by marigome          #+#    #+#             */
/*   Updated: 2024/06/12 09:33:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	char					*buffer_dst;
	const char				*buffer_src;

	i = 0;
	buffer_dst = (char *)dst;
	buffer_src = (const char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		buffer_dst[i] = buffer_src[i];
		i++;
	}
	return (dst);
}
