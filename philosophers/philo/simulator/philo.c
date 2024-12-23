/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:12 by marigome          #+#    #+#             */
/*   Updated: 2024/12/10 13:55:54 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	env;

	env.eat_max = 0;
	env.stopping = 0;
	if (argc < 5 || argc > 6)
		return (printf("Error: Wrong number of arguments\n"), 1);
	if (ft_check_args(&env, argc, argv))
		return (printf("CHAO\n\n"), 1);
	if (ft_init_philo_sim(&env))
		return (printf("Error: Memory allocation failed\n"), 1);
	if (ft_create_thread(&env))
		return (printf("Error: Thread creation failed\n"), 1);
	return (0);
}
