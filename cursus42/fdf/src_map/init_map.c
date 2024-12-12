/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:17:41 by marigome          #+#    #+#             */
/*   Updated: 2024/09/17 10:12:28 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	read_map(t_map *map, int fd)
{
	char	*line;
	char	**subline;

	line = get_next_line(fd);
	subline = NULL;
	while (line)
	{
		if (map->lines == 0)
		{
			subline = ft_split(line, 32);
			while (subline[map->columns])
				map->columns++;
			ft_free_split(subline);
		}
		map->lines++;
		free(line);
		line = get_next_line(fd);
	}
	lseek(fd, 0, SEEK_SET);
}

static int	fill_lines(t_map *map, char **subline, int row)
{
	int	i;

	i = 0;
	while (i < map->columns && subline[i] != NULL)
	{
		map->map[row][i] = (int *)malloc(2 * sizeof(int));
		if (!map->map[row][i])
		{
			ft_free_sub(map->map[row], i);
			return (0);
		}
		map->map[row][i][0] = ft_atoi(subline[i]);
		ft_check_commas(subline[i], map, row, i);
		i++;
	}
	return (1);
}

static int	allocate_lines(t_map *map, char *line, int i)
{
	char	**subline;

	map->map[i] = (int **)malloc(map->columns * sizeof(int *));
	if (!map->map[i])
	{
		ft_free_superarray(map, i);
		return (0);
	}
	subline = ft_split(line, ' ');
	if (!subline)
	{
		free(map->map[i]);
		ft_free_superarray(map, i);
		return (0);
	}
	if (!fill_lines(map, subline, i))
	{
		ft_free_split(subline);
		ft_free_superarray(map, i);
		return (0);
	}
	ft_free_split(subline);
	return (1);
}

static void	ft_complet_map(t_map *map, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	while (line && i < map->lines)
	{
		if (!allocate_lines(map, line, i))
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

t_map	*init_map(const char *map_name)
{
	t_map	*map;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_manage_err(INIT_E);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_manage_err(INIT_E);
	map->lines = 0;
	map->columns = 0;
	read_map(map, fd);
	map->map = (int ***)malloc(map->lines * sizeof(int **));
	if (!map->map)
	{
		ft_free_map(map);
		ft_manage_err(INIT_E);
	}
	ft_complet_map(map, fd);
	ft_read_z(map);
	close(fd);
	return (map);
}
