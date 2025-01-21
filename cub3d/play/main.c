/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:45:12 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:20:29 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Wrong number of args, please insert 2 arguments"), 1);
	ft_info_update(&data);
	if (ft_load_map(argv[1], &data) == FAILURE)
    {
        printf("Error: Failed to load map.\n");
        return (1);
    }

    printf("Map loaded successfully!\n");
    return (0);
}