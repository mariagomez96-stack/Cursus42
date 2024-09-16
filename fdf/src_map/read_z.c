/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:42:51 by marigome          #+#    #+#             */
/*   Updated: 2024/09/16 16:54:33 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_read_z(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->max_z = 0;
	map->min_z = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j][0] < map->min_z)
				map->min_z = map->map[i][j][0];
			if (map->map[i][j][0] > map->max_z)
				map->max_z = map->map[i][j][0];
			j++;
		}
		i++;
	}
}

static unsigned int	ft_htol(char *str)
{
	char			*hex_lower;
	char			*hex_upper;
	unsigned long	res;
	char			*ptr;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	res = 0;
	if (str[0] == 48 && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str != '\0')
	{
		ptr = ft_strchr(hex_lower, *str);
		if (ptr == NULL)
			ptr = ft_strchr(hex_upper, *str);
		if (ptr == NULL)
			break ;
		if (ft_strchr(hex_lower, *str))
			res = res * 16 + (ptr - hex_lower);
		else
			res = res * 16 + (ptr - hex_upper);
		str++;
	}
	return (res);
}

static int	ft_color_zcell(char *str, t_map *map, int row, int j)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (str[i] != ',' && str[i] != '\0')
	{
		z = (z * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] == ',')
		i++;
	map->map[row][j][1] = ft_htol(&str[i]);
	return (z);
}

int	ft_check_commas(char *str, t_map *map, int row, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (ft_color_zcell(str, map, row, j));
		map->map[row][j][1] = 0xffffff;
		i++;
	}
	return (ft_atoi(str));
}
