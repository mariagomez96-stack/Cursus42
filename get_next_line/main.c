/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:54:14 by marigome          #+#    #+#             */
/*   Updated: 2024/05/14 12:04:49 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*prueba;

	prueba = "prueba.txt";
	fd = open(prueba, O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
