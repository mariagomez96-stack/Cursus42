/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:35:28 by marigome          #+#    #+#             */
/*   Updated: 2024/09/13 10:53:13 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *src)
{
	ft_printf("Error: %s\n", src);
	exit(EXIT_FAILURE);
}

void	ft_free_columns(char **columns)
{
	int	i;

	i = 0;
	while (columns[i])
		free(columns[i++]);
	free(columns);
}

void	ft_free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free (argv);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (i < map->lines)
			free(map->map[i++]);
		free(map->map);
	}
	free(map);
}
