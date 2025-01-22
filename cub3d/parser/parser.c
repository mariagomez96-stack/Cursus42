/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:35:59 by marigome          #+#    #+#             */
/*   Updated: 2025/01/22 13:09:37 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_parse(char *cub, t_data *info)
{
	int	fd;
	int	fault_flag;

	fault_flag = 0;
	info->file = cub;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
	{
		printf(RED"Opening the map file failed.\n"RESET);
		return (FAILURE);
	}
	if (!ft_update_textures(info, &fault_flag, &fd))
        printf("Todo ok en ft_get_imgs_info.\n"); 
	return (fault_flag);
}