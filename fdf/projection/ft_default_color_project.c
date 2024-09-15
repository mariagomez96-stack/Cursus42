/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_color_project.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:09:47 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 10:10:30 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->max_z - map->min_z;
	if (max == 0)
		return (0xFFFFFF);
	percent = ((double)(z - map->min_z) / max);
	if (percent < 0.2)
		return (0x3366FF);
	else if (percent < 0.4)
		return (0x33CCFF);
	else if (percent < 0.6)
		return (0x33FF66);
	else if (percent < 0.8)
		return (0xFFFF66);
	else
		return (0xFF3333);
}
