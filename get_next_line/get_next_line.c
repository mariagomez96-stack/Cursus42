/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:04:15 by marigome          #+#    #+#             */
/*   Updated: 2024/05/16 13:58:57 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_buffer(char *buffer)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	len = ft_strlen(buffer);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	new_buffer = calloc(sizeof(char), (len - i));
	if (!new_buffer)
		return (NULL);
	if (buffer[i] != '\0')
		i++;
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer = ft_free_buffer(buffer);
	return (new_buffer);
}

char	*ft_free_buffer(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ptr);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (buffer[i] != '\0' || buffer[i] != '\n')
		i++;
	line = calloc(sizeof(char), (i + 2));
	while (buffer[j] != '\0' || buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_read_from_buffer(char *buffer, int fd)
{
	int		bytes_readed;
	char	*tmp;

	bytes_readed = 1;
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (bytes_readed >= 0)
	{
		bytes_readed = read(fd, tmp, BUFFER_SIZE);
		if (bytes_readed < 0)
			return (ft_free_buffer(buffer));
		else if (bytes_readed == 0)
			return (ft_calloc(1, 1));
		else
		{
			tmp[bytes_readed] = '\0';
			buffer = ft_strjoin(buffer, tmp);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
		tmp = ft_free_buffer(tmp);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (buffer == NULL)
		buffer = calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer || BUFFER_SIZE < 0 || read(fd, 0, 0) <= 0)
		return (0);
	buffer = ft_read_from_buffer(buffer, fd);
	line = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (line);
}
