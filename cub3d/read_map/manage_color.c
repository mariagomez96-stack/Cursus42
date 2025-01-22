/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:19:44 by marigome          #+#    #+#             */
/*   Updated: 2025/01/22 12:25:25 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	ft_rgb_to_hex_split(char **c)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	hex;
	char			**rgb;

	rgb = ft_split(c[1], ',');
	if (!rgb)
	{
		printf(RED"Failed in ft_split.\n"RESET);
		return (FAILURE);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_split_free(rgb);
	if (r > 255 || r < 1 || g > 255 || g < 1 || b > 255 || b < 1)
	{
		ft_error_color(c, r, g, b);
		return (FAILURE);
	}
	hex = (r << 24 | g << 16 | b << 8 | 0xFF);
	return (hex);
}
unsigned int	ft_rgb_to_hex(char **c)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	hex;

	if (!c || !c[0] || !c[1] || !c[2] || !c[3])
		return (FAILURE);
	r = ft_atoi(c[1]);
	g = ft_atoi(c[2]);
	b = ft_atoi(c[3]);
	if (r > 255 || r < 1 || g > 255 || g < 1 || b > 255 || b < 1)
	{
		ft_error_color(c, r, g, b);
		return (FAILURE);
	}
	hex = (r << 24 | g << 16 | b << 8 | 0xFF);
	return (hex);
}

unsigned int	ft_rgb_get(char **c)
{
	unsigned int	rgb;

	if (ft_split_len(c) == 2)
	{
		rgb = ft_rgb_to_hex_split(c);
		if (rgb == 1)
			rgb = 255;
	}
	if (ft_split_len(c) == 4)
	{
		rgb = ft_rgb_to_hex(c);
		if (rgb == 1)
			rgb = 255;
	}
	return (rgb);
}
