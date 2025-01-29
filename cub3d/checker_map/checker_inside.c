/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_inside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:38 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 09:40:34 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_players_count(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

int	ft_players_num(char **map)
{
	int	count;

	count = ft_players_count(map);
	if (count == 0 || count > 1)
	{
		ft_map_error("players", count, 0, 0);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' || c == '1' || c == '0' || c == '\n')
		return (1);
	return (0);
}

int	ft_check_inside(char **map)
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
			if (!ft_valid_char(map[i][j]))
			{
				ft_map_error("char", i, j, map[i][j]);
				error_flag = 1;
			}
			j++;
		}
		i++;
	}
	if (error_flag == 1)
		return (FAILURE);
	return (SUCCESS);
}