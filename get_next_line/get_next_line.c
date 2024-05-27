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

//#include "get_next_line.h"
#include <unistd.h> //write
#include <stdlib.h> //malloc
#include <stdio.h> //printf
#include <fcntl.h> //Para leer archivos



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
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
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

char	*ft_free_strjoin(char *buffer, char *tmp)
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

char	*ft_get_line(char *buffer)
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
		return (0);
	buffer = ft_read_from_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (line);
}

int main (void)
{
	int fd;
	char	*line;
	int	count;

	count = 0;

	fd = open("new.txt", O_RDONLY);
	printf("fd:%d\n", fd);
	if (fd == -1)
	{	
		printf("Error al abrir el archivo");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}