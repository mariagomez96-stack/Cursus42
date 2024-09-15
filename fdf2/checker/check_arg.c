/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:41:06 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 17:39:09 by marigome         ###   ########.fr       */
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
		ft_error(EXT_ERR);
		exit(EXIT_FAILURE);
	}
	else if (!ft_checker_ext(argv[1]))
	{
		ft_error("File as invalid extension");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
