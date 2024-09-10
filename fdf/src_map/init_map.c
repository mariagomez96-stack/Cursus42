/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:17:41 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 13:43:20 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map   *init_map(const char *map_name)
{
    t_map   *map;
    int     fd;
    
	map = initialize_map();
	if (!map)
		return (NULL);
	fd = open_map_file(map_name);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	if (!read_lines(map, fd))
	{
		close (fd);
		free_map(map);
		return (NULL);
	}
	close (fd);
	calculate_depth(map);
	return (map);
}