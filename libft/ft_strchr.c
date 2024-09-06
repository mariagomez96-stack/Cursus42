/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:14:09 by marigome          #+#    #+#             */
/*   Updated: 2024/06/12 09:33:38 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i])
	{
		if ((char)s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
