/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:14:09 by marigome          #+#    #+#             */
/*   Updated: 2024/04/12 09:47:11 by marigome         ###   ########.fr       */
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

/*#include <stdio.h>
int main(void)
{
	printf("%s", ft_strchr("hola que tal", '\0'));
	return (0);
}*/