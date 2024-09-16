/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:35:28 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 13:20:37 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_sub(int32_t **sub, int32_t size)
{
	int32_t	i;

	i = 0;
	while (i < size)
	{
		free(sub[i]);
		i++;
	}
	free (sub);
}

void	ft_free_split(char **columns)
{
	int	i;

	i = 0;
	while (columns[i])
		free(columns[i++]);
	free(columns);
}

void	ft_free_superarray(t_map *map, int32_t rows)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < map->columns)
		{
			free(map->map[i][j]);
			j++;
		}
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	ft_cleanup(t_map *map, char *line, char **split_line, int32_t row)
{
	if (split_line)
		ft_free_split(split_line);
	if (line)
		free(line);
	ft_free_superarray(map, row);
}

void	ft_free_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (map != NULL && map->map != NULL)
	{
		while (i < map->lines)
		{
			j = 0;
			if (map->map[i] != NULL)
			{
				while (j < map->columns)
				{
					free(map->map[i][j]);
					map->map[i][j] = NULL;
					j++;
				}
				free(map->map[i]);
				map->map[i] = NULL;
			}
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}
