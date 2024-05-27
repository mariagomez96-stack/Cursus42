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

static char	*ft_free_strjoin(char *buffer, char *tmp)
{
	char	*res;
	
	res = ft_strjoin(buffer, tmp);
	free(buffer);
	return (res);
}

static char	*ft_new_buffer(char *buffer)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	len = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{	
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(sizeof(char), (len - i) + 1);
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
	{
		new_buffer[j++] = buffer[i++];
	}
	free(buffer);
	return (new_buffer);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	while (buffer[j] != '\0' && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[j] = '\n';
	return (line);
}

static char	*ft_read_from_buffer(char *buffer, int fd)
{
	int		bytes_readed;
	char	*tmp;

	bytes_readed = 1;
	if (!buffer)
		ft_calloc(1, 1);
	tmp = ft_calloc(sizeof(char), 42 + 1);
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, tmp, 42);
		if (bytes_readed == -1)
		{
			free(tmp);
			return (NULL);
		}		
		tmp[bytes_readed] = 0;
		buffer = ft_free_strjoin(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free (tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (!buffer)
		buffer = ft_calloc(sizeof(char), (1));
	if (fd < 0 || 42 < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_from_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (line);
}

