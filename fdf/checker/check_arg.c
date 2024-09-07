/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:41:06 by marigome          #+#    #+#             */
/*   Updated: 2024/09/07 14:27:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_strncheck(char *src, char *look, int i)
{
	int	j;

	j = 0;
	while (look[j] && src[i])
	{
		if (src[i] != look[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

static int	ft_checker_ext(char *map_name)
{
	int	size;

	size = ft_strlen(map_name);
	if (size < 4)
	{
		mlx_strerror(MLX_INVEXT);
		//ft_error(NAME_ERR);
		exit(EXIT_FAILURE);
	}
	if (!ft_strncheck(map_name, ".fdf", size - 4))
	{
		mlx_strerror(MLX_INVEXT);
		//ft_error(NAME_ERR);
		exit(EXIT_FAILURE);
	}
	return (MLX_SUCCESS);
}

int	ft_checker_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error(ERROR_NUM_ARG);
		exit(EXIT_FAILURE);
	}
	if (ft_checker_ext(argv[1]) != EXIT_SUCCESS)
	{
		ft_error(MLX_INVEXT);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
