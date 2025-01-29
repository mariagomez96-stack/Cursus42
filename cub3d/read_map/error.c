/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:17:39 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 12:35:26 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error_color(char **path, int r, int g, int b)
{
	printf(RED"Bad rgb value\n"RESET);
	ft_putstr_fd(path[0], 2);
	ft_putstr_fd(". ", 2);
	if (r > 255 || r < 0)
	{
		ft_putstr_fd("r = ", 2);
		ft_putnbr_fd(r, 2);
		ft_putstr_fd(". ", 2);
	}
	if (g > 255 || g < 0)
	{
		ft_putstr_fd("g = ", 2);
		ft_putnbr_fd(g, 2);
		ft_putstr_fd(". ", 2);
	}
	if (b > 255 || b < 0)
	{
		ft_putstr_fd("b = ", 2);
		ft_putnbr_fd(b, 2);
		ft_putstr_fd(".", 2);
	}
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
void	ft_error_rgb_num(char **rgb, int i, int j, int line)
{
	printf("Bad argument: %c in line: %d\n", rgb[i][j], line);
	exit(EXIT_FAILURE);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

