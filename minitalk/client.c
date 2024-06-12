/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:09:57 by marigome          #+#    #+#             */
/*   Updated: 2024/06/12 12:00:33 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_char_to_bit(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit--;
		usleep(300);
	}
}

static int	ft_check_pid(char *arg)
{
	size_t	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if ((arg[i] < '0') | (arg[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;

	i = 0;
	if (argc <= 2)
		printf(RED MSG_ARG_1);
	else if (argc == 3)
	{
		ft_check_pid(argv[1]);
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_char_to_bit(pid, argv[2][i]);
			i++;
		}
	}
	else
		printf(RED MSG_ARG_2);
	return (0);
}
