/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:10:37 by marigome          #+#    #+#             */
/*   Updated: 2025/01/22 12:33:28 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_colors(char **c, int i)
{
	(void)i;
	if (ft_strcmp(c[0], "C") && ft_strcmp(c[0], "F"))
		return (SUCCESS);
	if (ft_split_len(c) == 2 && ft_check_comma(c) == 2)
		return (SUCCESS);
	else if (ft_split_len(c) == 4 && ft_check_comma(c) == 2)
		return (SUCCESS);
	else
	{
		if (ft_check_comma(c) != 2)
			printf(RED"Bad rgb format"RESET);
		if (ft_split_len(c) != 2 && ft_split_len(c) != 4)
			printf(RED"Bad rgb format"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_check_file(char *file, char *img, int i)
{
	int	fd;

	(void)i;
	if (!ft_strcmp(file, "C") || !ft_strcmp(file, "F"))
		return (SUCCESS);
	fd = open(img, O_RDONLY);
    printf("fd: %d\n", fd);
	if (fd < 0)
	{
		printf(RED"Failed to open the texture file\n"RESET);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	ft_check_bad_argument(char **c, int i)
{
	(void)i;
	if (c && c[2] && ft_strcmp(c[0], "C")
		&& ft_strcmp(c[0], "F") && c[0][0] != '1')
	{
		printf(RED"Extra argument in file\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_check_path(char **c, int i)
{
	if (!c[1])
	{
		printf(RED"Bad texture format in line: %d", i);
		printf("\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_check_cardinal(char **c, int line)
{
	(void)line;
	if (ft_strcmp(c[0], "NO") && ft_strcmp(c[0], "SO")
		&& ft_strcmp(c[0], "WE") && ft_strcmp(c[0], "EA")
		&& ft_strcmp(c[0], "F") && ft_strcmp(c[0], "C"))
	{
		printf(RED"Invalid identifier\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}