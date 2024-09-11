/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:17:41 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 13:37:06 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// New used //

t_map   *initialize_map(void)
{
    t_map   *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        mlx_strerror(MLX_MEMFAIL);
        return (NULL);
    }
    map->lines = 0;
    map->columns = -1;
    map->max_depth = 0;
    map->min_depth = 0;
    map->map = NULL;
    return (map);
}

static void read_map(t_map *map, int fd)
{
    char	*line;
	char	**subline;

	line = get_next_line(fd);
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


static void	fill_lines(t_map *map, char **columns, int row)
{
	int	col;
	int	i;

	col = 0;
	i = 0;
	while (col < map->columns && columns != NULL)
	{
		map->map[row][col] = (int *)malloc(sizeof(int));
		if (!map->map[row][col])
		{
			while (i < col)
				free(map->map[row][i++]);
			free(map->map[row]);
			return ;
		}
		map->map[row][col][0] = ft_atoi(columns[col]);
        col++;
	}
}

// New used //
static int	allocate_lines(t_map *map, char *line, int i)
{
	char	**subline;

	map->map[i] = (int **)malloc(map->columns * sizeof(int *));
	if (!map->map[i])
	{
		free(map->map[i]);
		return (0);
	}
	subline = ft_split(line, ' ');
	if (!subline)
	{	
		ft_free_split(subline);
		return (0);
	}
	ft_printf("Filas completadas\n");
	fill_lines(map, subline, i);
	ft_printf("Columnas añadidas al mapa\n");
	ft_free_split(subline);
	return (1);
}

// New used //
static void	ft_complet_map(t_map *map, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	while (line && i < map->lines)
	{
		ft_printf("Line readed\n");
		if (!allocate_lines(map, line, i))
		{
			free_map(map);
			return ;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
}


t_map   *init_map(const char *map_name)
{
    t_map   *map;
    int     fd;
    
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map = initialize_map();
	ft_printf("map initialized\n");
	fd = open_map_file(map_name);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	ft_printf("map opened\n");
	read_map(map, fd);
	map->map = (int ***)malloc(map->lines * sizeof(int **));
	if (!map->map)
		free_map(map);
	ft_printf("map readed\n");
	ft_complet_map(map, fd);
	close (fd);
	calculate_depth(map);
	return (map);
}