/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:46 by marigome          #+#    #+#             */
/*   Updated: 2024/05/16 13:22:47 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i])
	{
		if ((char)s[i] == (char)c)
			return (1);
		i++;
	}
	if ((char)s[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*buffer;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!buffer || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}
