/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:35:59 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 09:31:31 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_size_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("Map readed: %s\n", map->map[0]);
	if (!map->map)
		return ;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) > j)
		{	
			j = ft_strlen(map->map[i]);
			printf("j: %d\n", j);
		}

		i++;
		printf("i: %d\n", i);
	}
	map->map_size_x = j;
	map->map_size_y = i;
}


int	ft_parse(char *cub, t_data *info)
{
	int	fd;
	int	fault_flag;

	fault_flag = 0;
	info->file = cub;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
	{
		printf(RED"Opening the map file failed.\n"RESET);
		return (FAILURE);
	}
	if (ft_update_textures(info, &fault_flag, &fd) || ft_get_map(info, fd) || ft_check_map(info))
		fault_flag = 1;
	close (fd);
	ft_get_size_map(&info->map);
	printf("Map size: %d x %d\n", info->map.map_size_x, info->map.map_size_y);
	return (fault_flag);
}