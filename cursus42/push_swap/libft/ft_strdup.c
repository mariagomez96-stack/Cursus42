/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:43:01 by marigome          #+#    #+#             */
/*   Updated: 2024/06/12 10:05:16 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = (ft_strlen(s) + 1);
	ptr = (char *)malloc(i * sizeof(char));
	if (!ptr)
		return (NULL);
	else
		ft_memcpy(ptr, s, i);
	return (ptr);
}
