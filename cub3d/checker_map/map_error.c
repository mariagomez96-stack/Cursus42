/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:01:33 by marigome          #+#    #+#             */
/*   Updated: 2025/01/27 14:01:54 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_map_error(const char *error_type, int line, int col, char c)
{
	if (!ft_strcmp(error_type, "border"))
		printf(RED"Map error: Missing wall at line %d (side: %s)\n"RESET, line, col == 1 ? "left" : "right");
	else if (!ft_strcmp(error_type, "space"))
		printf(RED"Map error: Invalid space at line %d, column %d.\n"RESET, line + 1, col + 1);
	else if (!ft_strcmp(error_type, "char"))
		printf(RED"Map error: Invalid character '%c' at line %d, column %d.\n"RESET, c, line + 1, col + 1);
	else if (!ft_strcmp(error_type, "players"))
		printf(RED"Map error: Wrong number of players. Players in map: %d\n"RESET, line);
}