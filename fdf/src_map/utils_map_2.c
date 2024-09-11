/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:13:29 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 13:33:40 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// used //
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

// New used //


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