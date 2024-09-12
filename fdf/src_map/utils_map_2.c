/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:13:29 by marigome          #+#    #+#             */
/*   Updated: 2024/09/12 15:22:03 by marigome         ###   ########.fr       */
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
