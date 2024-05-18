/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:50:27 by marigome          #+#    #+#             */
/*   Updated: 2024/05/14 12:22:36 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

//Esta función me permite ver dentro de tmp la línea real

char	*ft_free_pointer(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	*check_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*bf_line;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	bf_line = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!bf_line)
		return (NULL);
	else
	{
		while (buffer[j] != '\0' && buffer != '\n')
		{
			bf_line[j] = buffer[j];
			j++;
		}
		if (buffer[j] == '\n')
			bf_line[j] = '\n';
		bf_line[j] = '\0';
	}
	return (bf_line);
}

char	*read_buff(char *buffer, int fd)
{
	//Creo un buffer tmp para ir guardando la información
	char	*buffer_tmp;
	ssize_t	bytes;
	//Igualo bytes a 1 para entrar al bucle
	bytes = 1;
	buffer_tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer_tmp)
		return (NULL);
	while (bytes > 0)
	{
		//Leo el archivo, 42 iteraciones y lo guardo en bf_tmp
		bytes = read(fd, buffer_tmp, BUFFER_SIZE);
		//Protegemos si read da error y liberamos
		if (bytes <= 0)
		{
			ft_free_pointer(buffer);
			return (ft_free_pointer(buffer_tmp));
		}
		//Ponemos al final carácter nulo para que sea una cadena
		buffer_tmp[bytes] = '\0';
		buffer = ft_join(buffer, buffer_tmp);
		if (*buffer_tmp == '\n')
			break ;
	}
	return (buffer);
}

char	*new_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	j = ft_strlen(buffer);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	new_buffer = ft_calloc(sizeof(char), (j - i) + 1);
	while (buffer[i])
	{
		new_buffer[k++] = buffer[i++];
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*ft_get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	else
	{
		buffer = read_buff(buffer, fd);
		line = check_line(buffer);
		buffer = new_buffer(buffer);
	}
	return (line);
}
