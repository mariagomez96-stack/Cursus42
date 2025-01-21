/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:56:33 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:16:52 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error_bad_spc(int line, int i)
{
	printf(RED"Invalid space"RESET" in line: ");
	ft_putnbr_fd(line + 1, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(i + 1, 2);
	ft_putstr_fd(".\n", 2);
}

int	ft_check_spaces(char **map)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				res = ft_check_spaces_map(map, i, j, res);
				res = ft_check_spaces_map_2(map, i, j, res);
			}
			j++;
		}
		i++;
	}
	if (res == 1)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_spaces_map_2(char **map, int i, int j, int res)
{
	if (j != 0)
	{
		if (map[i][j - 1] == ' ')
		{
			ft_error_bad_spc(i, j - 1);
			res = 1;
		}
	}
	if ((size_t)j != ft_strlen(map[i]))
	{
		if (map[i][j + 1] == ' ')
		{
			ft_error_bad_spc(i, j + 1);
			res = 1;
		}
	}
	return (res);
}

int	ft_check_spaces_map(char **map, int i, int j, int res)
{
	if (i != 0)
	{
		if (map[i - 1][j] == ' ')
		{
			ft_error_bad_spc(i - 1, j);
			res = 1;
		}
	}
	if (i != ft_split_len(map))
	{
		if (map[i + 1][j] == ' ')
		{
			ft_error_bad_spc(i + 1, j);
			res = 1;
		}
	}
	return (res);
}
