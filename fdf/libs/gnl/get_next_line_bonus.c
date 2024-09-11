/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:04:15 by marigome          #+#    #+#             */
/*   Updated: 2024/05/28 11:57:23 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free_strjoin2(char *buffer, char *tmp)
{
	char	*res;

	res = ft_strjoin_mine2(buffer, tmp);
	free(buffer);
	return (res);
}

static char	*ft_new_buffer2(char *buffer)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	len = ft_strlen_mine2(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{	
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc_mine2(sizeof(char), (len - i) + 1);
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

static char	*ft_get_line2(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc_mine2(sizeof(char), (i + 2));
	while (buffer[j] != '\0' && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[j] = '\n';
	return (line);
}

static char	*ft_read_from_buffer2(char *buffer, int fd)
{
	int		bytes_readed;
	char	*tmp;

	bytes_readed = 1;
	if (!buffer)
		ft_calloc_mine2(1, 1);
	tmp = ft_calloc_mine2(sizeof(char), BUFFER_SIZE + 1);
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, tmp, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(tmp);
			return (NULL);
		}		
		tmp[bytes_readed] = 0;
		buffer = ft_free_strjoin2(buffer, tmp);
		if (ft_strchr_mine2(tmp, '\n'))
			break ;
	}
	free (tmp);
	return (buffer);
}

char	*get_next_line2(int fd)
{
	static char	*buffer[FD_SETSIZE];
	char		*line;

	if (!buffer[fd])
		buffer[fd] = ft_calloc_mine2(sizeof(char), (1));
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buffer[fd] = ft_read_from_buffer2(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line2(buffer[fd]);
	buffer[fd] = ft_new_buffer2(buffer[fd]);
	return (line);
}
