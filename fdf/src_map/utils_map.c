/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:57:51 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 19:15:13 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int create_map_row(t_map *map, int row)
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


int	columns_to_map(t_map *map, char **columns, int row)
{
	int	col;
	int	i;

	col = 0;
	i = 0;
	while (col < map->columns)
	{
		map->map[row][col] = (int *)malloc(sizeof(int) * 2);
		if (!map->map[row][col])
		{
			while (i < col)
				free(map->map[row][i++]);
			free(map->map[row]);
			return (0);
		}
		map->map[row][col][0] = col;
		map->map[row][col][1] = ft_atoi(columns[col]);
        col++;
	}
	return (1);
}

int	process_line(t_map *map, char *line, int row)
{
	char	**columns;

	columns = split_lines_in_columns(line);
	if (!columns)
		return (0);
    if (!create_map_row(map, row))
    {
        ft_free_columns(columns);
        return (0);
    }
    if (!columns_to_map(map, columns, row))
    {
        ft_free_columns(columns);
        return (0);
    }
    ft_free_columns(columns);
    return (1);
}
