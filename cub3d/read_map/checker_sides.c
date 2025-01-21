/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sides.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:40:44 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:16:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_checker_borders(char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ')
		i++;
	if (c[i] != '1')
		return (FAILURE);
    i = ft_strlen(c) - 1;
	while (c[i] == ' ')
		i--;
	if (c[i] != '1')
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_sides(char **map)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		if (ft_checker_borders(map[i]))
        {
            printf(RED"The map is not closed.\n"RESET);
		    ft_putstr_fd(".\n", 2);
        }
		i++;
	}
	if (res == 1)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_map_closed(t_data *info)
{
	int	res;

	res = 0;
	if (ft_check_sides(info->map.map))
		res = 1;
	if (res == 1)
		return (FAILURE);
	return (SUCCESS);
}

