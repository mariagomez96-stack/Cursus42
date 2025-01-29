/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:04:08 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 12:05:59 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_texture_missed(t_data *info)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	int		*flags[] = { &info->textures.color_flag, &info->textures.floor_flag,
	                    &info->textures.no_flag, &info->textures.so_flag,
	                    &info->textures.we_flag, &info->textures.ea_flag };

	while (i < 6)
	{
		if (*flags[i] != 1)
			count++;
		i++;
	}
	return (count);
}


void	ft_new_fd(t_data *info, int i, int *fd)
{
	int		j;
	int		k = 0;
	char	*line;

	j = ft_texture_missed(info);
	k = 0;
	if (j == 0)
		return;
	close(*fd);
	*fd = open(info->file, O_RDONLY);
	if (*fd < 0)
		return;
	while (k <= i - j)
	{
		line = get_next_line(*fd);
		if (line)
		{
			if (ft_strcmp(line, "\n") != 0) // Evitar contar líneas vacías
				k++;
			free(line);
		}
	}
}

char	*ft_remove_newline(char *str)
{
	char	*new_str;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len == 0)
		return (str); // No hace falta modificarlo si está vacío
	new_str = malloc(len);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(new_str, str, len - 1); // Copiamos sin '\n'
	new_str[len - 1] = '\0';
	free(str);
	return (new_str);
}

/*FT_PROCESS_LINE:
	Lee una línea del archivo y elimina el salto de línea \n */

int	ft_process_line(char ***tokens, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		printf(RED"Error: Failed to read the line.\n"RESET);
		return (FAILURE);
	}
	line = ft_remove_newline(line); // Elimina el salto de línea
	if (!line)
	{
		printf(RED"Error: Memory allocation failed.\n"RESET);
		return (FAILURE);
	}
	*tokens = ft_split(line, ' '); // Divide la línea en tokens
	free(line);
	if (!*tokens)
	{
		printf(RED"Error: ft_split failed.\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	ft_checker_textures(t_data *info, int *fd, int i)
{
	int	j;
	const char *identifiers[] = { "C", "F", "NO", "SO", "WE", "EA" };
	int *flags[] = { &info->textures.color_flag, &info->textures.floor_flag,
	                 &info->textures.no_flag, &info->textures.so_flag,
	                 &info->textures.we_flag, &info->textures.ea_flag };

	j = 0;
	ft_new_fd(info, i, fd);
	while(j < 6)
	{
		if (*flags[j] != 1)
			printf(RED"Error: \"%s\" identifier is missing.\n"RESET, identifiers[j]);
		j++;
	}

}

