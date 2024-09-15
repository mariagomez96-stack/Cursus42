/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_color_project.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:09:47 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 18:44:58 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_get_default_color(int z, t_map *map) 
{
    double			percent;
    unsigned int	max;

    max = map->max_z - map->min_z; // Rango de alturas
    if (max == 0) return (0xFFFFFF); // Si no hay variación, devuelve blanco
    percent = ((double)(z - map->min_z) / max); // Porcentaje de altura
    if (percent < 0.2) return (0x3366FF); // Diferentes colores según el porcentaje
    else if (percent < 0.4) return (0x33CCFF);
    else if (percent < 0.6) return (0x33FF66);
    else if (percent < 0.8) return (0xFFFF66);
    else return (0xFF3333);
}



