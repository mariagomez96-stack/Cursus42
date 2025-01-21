/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:26:37 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:39:53 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_extra(char *map)
{
	int	i;

	i = 0;
	if (!map || !map[i] || map[i] == '\n')
	{
		printf(RED"Map is missing.\n"RESET);
		return (FAILURE);
	}
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] != '\0' && map[i] == ' ')
				i++;
			if (map[i] == '\n')
			{
				printf(RED"There is an extra line in map.\n"RESET);
				return (FAILURE);
			}
		}
		if (map[i] != '\0')
			i++;
	}
	return (SUCCESS);
}

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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
	int	i;

	i = ft_players_count(map);
	if (i == 0)
	{
		printf(RED"Missing player in map.\n"RESET);
		return (FAILURE);
	}
	if (i > 1)
	{
		printf(RED"Too many players in map."RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

