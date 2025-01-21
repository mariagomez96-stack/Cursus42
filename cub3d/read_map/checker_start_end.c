/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_start_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:47:38 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:38:43 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_check_inside(char **map)
{
    int i, j;

    if (!map)
        return (FAILURE);

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' &&
                map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' && 
                map[i][j] != ' ')
            {
                printf("Error: Invalid character '%c' in map at [%d][%d]\n", map[i][j], i, j);
                return (FAILURE);
            }
            j++;
        }
        i++;
    }
    return (SUCCESS);
}


int	ft_check_start_and_end(char **map, int end)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
		{
			printf(RED"Invalid character in the first line.\n"RESET);
			return (FAILURE);
		}
		i++;
	}
    i = 0;
    while (map[end - 1][i])
	{
		if (map[end - 1][i] != ' ' && map[end - 1][i] != '1')
		{
			printf(RED"Invalid character in the last line of the map\n"RESET);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_check_first_last(t_data *info, char **map)
{

	if (ft_check_start_and_end(map, info->map.map_line))
	{	
        return (FAILURE);
    }
	return (SUCCESS);
}