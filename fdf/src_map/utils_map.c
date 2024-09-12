/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:57:51 by marigome          #+#    #+#             */
/*   Updated: 2024/09/12 18:01:57 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*initialize_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		mlx_strerror(MLX_MEMFAIL);
		return (NULL);
	}
	map->lines = 0;
	map->columns = 0;
	map->map = NULL;
	return (map);
}

int	open_map_file(const char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_error(FILE_OPEN_ERROR);
		return (-1);
	}
	return (fd);
}

int	create_map_row(t_map *map, int row)
{
	map->map[row] = (int **)malloc(sizeof(int *) * map->columns);
	if (!map->map[row])
		return (0);
	return (1);
}

char	**split_lines_in_columns(char *line)
{
	char	**columns;

	columns = ft_split(line, ' ');
	if (!columns)
		return (NULL);
	return (columns);
}

int	ft_columns_counter(char *line)
{
	int		counter;
	char	**columns;
	int		i;

	counter = 0;
	i = 0;
	columns = split_lines_in_columns(line);
	while (columns[counter])
		counter++;
	while (columns[i])
	{
		free(columns[i]);
		i++;
	}
	free(columns);
	return (counter);
}
