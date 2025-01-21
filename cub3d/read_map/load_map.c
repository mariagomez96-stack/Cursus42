/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:17:56 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:16:39 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int ft_load_map(char *file, t_data *info)
{
    int fd;
    char *map_str;

    if (ft_checker_extension(file) == FAILURE)
        return (FAILURE);

    fd = ft_open_map_file(file);
    if (fd == FAILURE)
        return (FAILURE);

    map_str = ft_read_map(fd);
    close(fd);
    if (!map_str)
        return (FAILURE);

    if (ft_process_map(info, map_str) == FAILURE)
    {
        free(map_str);
        return (FAILURE);
    }
    free(map_str);

    if (ft_validate_map(info) == FAILURE)
        return (FAILURE);

    ft_calculate_map_size(&info->map);
    return (SUCCESS);
}
