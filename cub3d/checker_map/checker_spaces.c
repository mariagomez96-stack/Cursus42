/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:12 by marigome          #+#    #+#             */
/*   Updated: 2025/01/27 14:02:35 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_adjacent_spaces(char **map, int i, int j)
{
	if (i > 0)
	{
		if (map[i - 1][j] == ' ')
			return (1);
	}
	if (map[i + 1])
	{
		if (map[i + 1][j] == ' ')
			return (1);
	}
	return (0);
}

int	ft_is_player_or_zero(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}


int	ft_check_spaces(char **map)
{
	int	i;
	int	j;
	int	error_flag;

	i = 0;
	error_flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_player_or_zero(map[i][j]))
			{
				if (ft_check_adjacent_spaces(map, i, j))
				{
					ft_map_error("space", i, j, 0);
					error_flag = 1;
				}
			}
			j++;
		}
		i++;
	}
	if (error_flag == 1)
		return (FAILURE);
	return (SUCCESS);
}