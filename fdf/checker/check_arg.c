/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:41:06 by marigome          #+#    #+#             */
/*   Updated: 2024/09/17 10:14:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_checker_ext(char *map_name)
{
	int	size;

	size = ft_strlen(map_name);
	if (size < 4)
	{
		mlx_strerror(MLX_INVEXT);
		return (0);
	}
	if ((ft_strncmp(map_name + size - 4, ".fdf", 4) != 0))
	{
		mlx_strerror(MLX_INVEXT);
		return (0);
	}
	return (1);
}

int	ft_checker_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_manage_err(ERROR_NUM_ARG);
		exit(EXIT_FAILURE);
	}
	else if (!ft_checker_ext(argv[1]))
	{
		ft_manage_err("File as invalid extension");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	clean_fdf(t_fdf *fdf)
{
	if (fdf->mlx)
		mlx_terminate(fdf->mlx);
	if (fdf->mouse)
		free(fdf->mouse);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->map)
		ft_free_map(fdf->map);
	free(fdf);
}

void	ft_control_map(char **argv, t_map *map)
{
	(void) argv;
	if (!map || !map->map)
	{
		ft_printf("Map or superarray is NULL\n");
		ft_manage_err(INIT_E);
	}
	ft_printf(ORANGE "Map dimensions: " RESET GREEN "Width " RESET "%d, " \
	GREEN"Height " RESET "%d\n", map->columns, map->lines);
}

void	ft_manage_err(const char *err)
{
	ft_printf("Error: %s\n", err);
	exit (EXIT_FAILURE);
}
