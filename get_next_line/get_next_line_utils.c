/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:42:46 by marigome          #+#    #+#             */
/*   Updated: 2024/05/14 13:38:04 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i])
		i++;
	return (i);
}

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

char	*ft_join(char *buffer, char *buffer_tmp)
{
	char	*buffer_joined;
	size_t	total_len;

	total_len = ft_strlen(buffer) + ft_strlen(buffer_tmp);
	buffer_joined = (char *)ft_calloc(sizeof(char), (total_len + 1));
	if (!buffer_joined)
		return (NULL);
	while (*buffer)
	{
		*buffer_joined = *buffer;
		buffer_joined++;
		buffer++;
	}
	while (*buffer_tmp)
	{
		*buffer_joined = *buffer_tmp;
		buffer_joined++;
		buffer_tmp++;
	}
	*buffer_joined = '\0';
	free(buffer_tmp);
	return (buffer_joined);
}
