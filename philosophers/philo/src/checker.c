/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:55:03 by marigome          #+#    #+#             */
/*   Updated: 2024/12/10 14:08:39 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_is_int(char *str)
{
	long	num;

	num = 0;
	num = ft_atoi(str);
	if (num >= INTMAX || num <= -INTMIN)
		return (1);
	return (0);
}

int	ft_check_args(t_data *env, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_int(argv[i]))
			return (printf("Error: Argument %i is not an integer\n", i), 1);
		if (ft_atoi(argv[i]) < 0)
			return (printf("Error: Argument %i is negative\n", i), 1);
		i++;
	}
	ft_init_env(env, argc, argv);
	if (env->philo_eat_limit < 1 || env->time_to_die < 1
		|| env->time_to_eat < 1 || env->time_to_sleep < 1)
		return (printf("Error: Arguments must be greater than 0\n"), 1);
	return (0);
}