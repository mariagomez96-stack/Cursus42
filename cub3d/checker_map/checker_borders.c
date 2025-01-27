/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_borders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:33:05 by marigome          #+#    #+#             */
/*   Updated: 2025/01/27 14:02:58 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_border_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
		{
			printf(RED"Invalid character in map border.\n"RESET);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}


int	ft_check_first_last(t_data *info, char **map)
{
	if (ft_check_border_line(map[0]))
		return (FAILURE);
	if (ft_check_border_line(map[info->map.map_line - 1]))
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_border_char(char *line, int is_left)
{
	int	i;

	if (is_left == 1)
		i = 0;
	else
		i = ft_strlen(line) - 1;

	while (line[i] == ' ')
	{
		if (is_left == 1)
			i++;
		else
			i--;
	}
	if (line[i] != '1')
		return (FAILURE);
	return (SUCCESS);
}


int	ft_check_sides(char **map)
{
	int	i;
	int	error_flag;

	i = 0;
	error_flag = 0;
	while (map[i])
	{
		if (ft_check_border_char(map[i], 1)) // Chequeo del lado izquierdo
		{
			ft_map_error("border", i + 1, 1, 0);
            error_flag = 1;
		}
		if (ft_check_border_char(map[i], 0)) // Chequeo del lado derecho
		{
			ft_map_error("border", i + 1, 2, 0);
			error_flag = 1;
		}
		i++;
	}
	if (error_flag == 1)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_map(t_data *info)
{
	if (!info || !info->map.map)
		exit (FAILURE);

	// 🔹 Chequear que la primera y última línea son paredes
	if (ft_check_first_last(info, info->map.map))
		exit (FAILURE);

	// 🔹 Chequear que los lados izquierdo y derecho están cerrados
	if (ft_check_sides(info->map.map))
		exit (FAILURE);

	// 🔹 Chequear caracteres inválidos dentro del mapa
	if (ft_check_inside(info->map.map))
		exit (FAILURE);

	// 🔹 Chequear que los espacios no están incorrectamente rodeando "0" o jugadores
	if (ft_check_spaces(info->map.map))
		exit (FAILURE);

	// 🔹 Chequear que haya **exactamente 1 jugador**
	if (ft_players_num(info->map.map))
		exit (FAILURE);

	return (SUCCESS);
}


