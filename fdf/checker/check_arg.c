/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:41:06 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 11:48:14 by marigome         ###   ########.fr       */
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
		//ft_error(NAME_ERR);
		return (0);
	}
	if (ft_strnstr(map_name, ".fdf\0", 6) == 0)
	{
		mlx_strerror(MLX_INVEXT);
		//ft_error(NAME_ERR);
		return (0);
	}
	return (1);
}

int	ft_checker_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error(ERROR_NUM_ARG);
		exit(EXIT_FAILURE);
	}
	else if (ft_checker_ext(argv[1]) != 1)
	{
		ft_error("File as invalid extension");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
