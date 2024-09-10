/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:13:29 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 19:17:53 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int open_map_file(const char *map_name)
{
    int fd;

    fd = open(map_name, O_RDONLY);
    if (fd < 0)
    {
        ft_error(FILE_OPEN_ERROR);
        return (-1);
    }
    return (fd);
}

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

int read_lines(t_map *map, int fd)
{
    char    *line;
    int     row;

    row = 0;
    while ((line = get_next_line(fd)))
    {
        if (map->columns == -1)
            map->columns = ft_columns_counter(line);
        if (map->map == NULL)
        {
            map->map = (int ***)malloc(sizeof(int **) * map->lines);
            if (!map->map)
            {
                free(line);
                return (0);
            }
        }
        if (!process_line(map, line, row))
        {
            free(line);
            return (0);
        }
        free(line);
        row++;
        map->lines++;
    }
    return (1);
}

void    update_depth(t_map *map, int z)
{
    if (z < map->min_depth)
        map->min_depth = z;
    if (z > map->max_depth)
        map->max_depth = z;
}

void    calculate_depth(t_map *map)
{
    int row;
    int col;
    int z;
    
    row = 0;
    col = 0;
    map->min_depth = INT_MAX;
    map->max_depth = INT_MIN;
    while (row < map->lines)
    {
        while (col < map->columns)
        {
            z = map->map[row][col][1];
            update_depth(map, z);
            col++;
        }
        row++;
    }
}