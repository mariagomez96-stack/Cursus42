/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:35:55 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 13:31:17 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_text(t_data *info, char **c, int *i, int line)
{
	if (!c[0])
	{
		ft_split_free(c);
		return (SUCCESS);
	}
	if (ft_check_imgs(c, line))
		return (FAILURE);
	ft_store_texture(info, c);
	ft_split_free(c);
	(*i)++;
	return (SUCCESS);
}

int	ft_check_comma(char **c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == ',')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int	ft_check_imgs(char **c, int i)
{
	if (ft_check_cardinal(c, i) ||
			ft_check_path(c, i) ||
			ft_check_bad_argument(c, i) ||
			ft_check_file(c[0], c[1], i) ||
			ft_check_colors(c, i) ||
			ft_check_colors_num(c, i))
			exit(EXIT_FAILURE);
	return (SUCCESS);
}

int	ft_check_colors_num(char **c, int line)
{
	int	flag;
	int	i;
	int	j;

	i = 1;
	flag = 0;
	if (ft_strcmp(c[0], "F") && ft_strcmp(c[0], "C"))
		return (SUCCESS);
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (!ft_isdigit(c[i][j]) && c[i][j] != ',')
			{
				ft_error_rgb_num(c, i, j, line);
				flag = 1;
			}
			j++;
		}
		i++;
	}
	if (flag == 1)
		return (FAILURE);
	return (SUCCESS);
}