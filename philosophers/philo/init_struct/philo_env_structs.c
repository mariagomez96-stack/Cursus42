/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_env_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:08:19 by marigome          #+#    #+#             */
/*   Updated: 2024/12/11 17:44:55 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_env(t_data *env, int argc, char *argv[])
{
	env->philo_count = 0;
	env->time_to_die = 0;
	env->time_to_eat = 0;
	env->time_to_sleep = 0;
	env->philo_eat_limit = 0;
	env->philo_count = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->philo_eat_limit = ft_atoi(argv[5]);
	else
		env->philo_eat_limit = 0;
}

int	ft_init_philos(t_data *env)
{
	int	i;

	i = 0;
	while (i < env->philo_count)
	{
		env->philos[i].eat_count = 0;
		env->philos[i].id = i + 1;
		env->philos[i].status = ft_itoa(i + 1);
		if (!env->philos[i].status)
			break ;
		env->philos[i].right_fork = i;
		env->philos[i].left_fork = (i + 1) % env->philo_count;
		env->philos[i].data = env;
		i++;
	}
	if (i != env->philo_count)
	{		
		while (i >= 0)
		{
			free(env->philos[i].status);
			i--;
		}
		return (1);
	}
	return (0);
}

