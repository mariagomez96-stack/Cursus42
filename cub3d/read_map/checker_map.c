/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:55:15 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:30:39 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* This function checker the extension of 
    the image used. It must be .cub */
int ft_checker_extension(char *file)
{
    char *extension;

    if (!file)
        return (FAILURE);
    extension = ft_strrchr(file, '.'); // Encuentra la última ocurrencia de '.'
    if (!extension || ft_strlen(extension) != 4 || ft_strncmp(extension, ".cub", 4))
    {
        printf("Error: Extension must be .cub\n");
        return (FAILURE);
    }
    return (SUCCESS);
}

int ft_open_map_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Failed to open the map file.\n");
        return (FAILURE);
    }
    return (fd);
}

char *ft_read_map(int fd)
{
    char *line;
    char *map;

    map = NULL;
    while ((line = get_next_line(fd))) // Leer cada línea del archivo
    {
        map = ft_strjoin_free(map, line); // Concatenar líneas
        free(line); // Liberar línea después de usarla
        if (!map)
        {
            printf("Error: Failed in ft_strjoin_safe.\n");
            return (NULL);
        }
    }
    return (map);
}

int ft_process_map(t_data *info, char *map_str)
{
    char *trimmed_map;

    trimmed_map = ft_trim_str(map_str, "\n"); // Eliminar saltos de línea
    if (!trimmed_map)
    {
        printf("Error: Failed in ft_trim_str.\n");
        return (FAILURE);
    }
    if (ft_split_map(info, trimmed_map)) // Convierte la cadena en un array de strings
        return (FAILURE);
    return (SUCCESS);
}

int ft_validate_map(t_data *data)
{
    if (!data || !data->map.map)
        return (FAILURE);
    if (ft_check_first_last(data, data->map.map) || 
        ft_check_map_closed(data) || 
        ft_check_inside(data->map.map) || 
        ft_check_spaces(data->map.map) || 
        ft_players_num(data->map.map))
    {
        printf("Error: Invalid map structure.\n");
        return (FAILURE);
    }
    return (SUCCESS);
}
